package l_read;

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;

import picocli.CommandLine;
import picocli.CommandLine.ArgGroup;
import picocli.CommandLine.Command;
import picocli.CommandLine.Option;
import picocli.CommandLine.Parameters;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.lang.reflect.Type;
import java.util.Base64;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.Callable;

@Command(name = "LogRead")
class LogRead implements Callable<Integer> {

	String token;

	@Option(names = { "-K", "--token" }, description = "Token used to authenticate the log.", required = true)
	public void ValidateTokenForm(String value) {
		if (value.matches("[a-zA-Z0-9]+")) {
			token = value;
		} else {
			System.out.println("invalid");
			System.exit(255);
		}
	}

	@ArgGroup(exclusive = true, multiplicity = "1")
	Mode mode;

	static class Mode {

		@Option(names = { "-S" })
		boolean getState;

		@ArgGroup(exclusive = false)
		RoomOrTime roomOrTime;

		static class RoomOrTime {

			@ArgGroup(exclusive = true, multiplicity = "1")
			Options options;

			static class Options {
				@Option(names = { "-R" })
				boolean getRooms;

				@Option(names = { "-T" })
				boolean getTime;

				@Option(names = { "-I" })
				boolean getRoomsOptional;
			}

			// Check if names only contain letters + no spaces
			@ArgGroup(exclusive = true, multiplicity = "1")
			Role role;

			static class Role {
				String employeeName;

				@Option(names = { "-E" })
				public void ValidateEmployeeNameForm(String value) {
					if (value.matches("[a-zA-Z]+")) {
						employeeName = value;
					} else {
						System.out.println("invalid");
						System.exit(255);
					}
				}

				String guestName;

				@Option(names = { "-G" })
				public void ValidateguestNameForm(String value) {
					if (value.matches("[a-zA-Z]+")) {
						guestName = value;
					} else {
						System.out.println("invalid");
						System.exit(255);
					}
				}

				public String getName() {
					if (employeeName != null) {
						return employeeName;
					} else
						return guestName;
				}

				public String getStatus() {
					if (employeeName != null)
						return "employee";
					else
						return "guest";
				}
			}
		}

	}

	@Parameters(index = "0")
	private String log;

	private static byte[] getBytesFromString(String string) {
		String[] strings = string.replace("[", "").replace("]", "").split(", ");
		byte result[] = new byte[strings.length];
		for (int i = 0; i < result.length; i++) {
			result[i] = Byte.parseByte(strings[i]);
		}
		return result;
	}

	public static byte[] getSalt(File file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(file));
		String salt = reader.readLine();
		reader.close();

		return getBytesFromString(salt);
	}

	public static IvParameterSpec getIV(File file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(file));

		// NOTE maybe use a better way to get the second line in the file.
		reader.readLine();
		String ivString = reader.readLine();
		reader.close();

		return new IvParameterSpec(getBytesFromString(ivString));
	}

	public static SecretKey getSecretKeyFromToken(String token, byte[] salt) throws Exception {
		SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
		PBEKeySpec spec = new PBEKeySpec(token.toCharArray(), salt, 100, 256);
		SecretKey secret = new SecretKeySpec(factory.generateSecret(spec).getEncoded(), "AES");
		return secret;
	}

	private static String decryptData(String data, SecretKey secretKey, IvParameterSpec iv) throws Exception {
		byte[] decryptedBytes = {};
		try {
			Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
			cipher.init(Cipher.DECRYPT_MODE, secretKey, iv);

			byte[] decodedBytes = Base64.getDecoder().decode(data);
			decryptedBytes = cipher.doFinal(decodedBytes);
		} catch (Exception e) {
			System.out.println("integrity violation");
			System.exit(255);
		}
		return new String(decryptedBytes);

	}

	private static String readFromFile(File file, String token) throws Exception {
		try {
			StringBuilder content = new StringBuilder();
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String line;
			while ((line = reader.readLine()) != null) {
				content.append(line);
			}
			reader.close();

			// decrypting data
			File file_config = new File(file + "_config");
			byte[] salt = getSalt(file_config);
			SecretKey secretKey = getSecretKeyFromToken(token, salt);

			IvParameterSpec iv = getIV(file_config);

			return decryptData(content.toString(), secretKey, iv);
		} catch (Exception e) {
			System.out.println("invalid");
			System.exit(255);
		}
		return "-1";
	}

	public static String getStateOfLog(String log, String token) throws Exception {
		String[] log_name = log.split("/");
		String log_file = log_name[log_name.length - 1];
		// TODO !
		// File file = new File("logs/" + log + "_dir/" + log_file);

		File file = new File(log_file);
		String existingData = readFromFile(file, token);

		Gson gson = new GsonBuilder().setPrettyPrinting().create();

		Type type = new TypeToken<Map<Integer, Map<String, String>>>() {
		}.getType();
		Map<Integer, Map<String, String>> existingMap = gson.fromJson(existingData, type);

		StringBuilder stateBuilder = new StringBuilder();

		// Collect employees and guests
		Set<String> employees = new TreeSet<>();
		Set<String> guests = new TreeSet<>();

		// Collect room information
		Map<Integer, Set<String>> roomInfo = new TreeMap<>();

		for (Map.Entry<Integer, Map<String, String>> entry : existingMap.entrySet()) {
			Map<String, String> id = entry.getValue();
			String name = id.get("name");
			String status = id.get("status");
			String roomIDStr = id.get("roomID");
			String event = id.get("event");

			if (status.equals("employee")) {
				if (event.equals("A")) {
					employees.add(name);
				} else if (Objects.equals(roomIDStr, "null")) {
					employees.remove(name);
				}
			} else {
				if (event.equals("A")) {
					guests.add(name);
				} else if (Objects.equals(roomIDStr, "null")) {
					guests.remove(name);
				}
			}

			if (!roomIDStr.equals("null")) {
				int roomID = Integer.parseInt(roomIDStr);
				if (event.equals("A")) {
					roomInfo.computeIfAbsent(roomID, k -> new TreeSet<>()).add(name);
				} else {
					Set<String> occupants = roomInfo.get(roomID);
					occupants.remove(name);
				}
			}
		}

		// Build the state string
		stateBuilder.append(String.join(",", employees)).append("\n");
		stateBuilder.append(String.join(",", guests));

		for (Map.Entry<Integer, Set<String>> entry : roomInfo.entrySet()) {
			if (!(entry.getValue().isEmpty())) {
				int roomID = entry.getKey();
				Set<String> occupants = entry.getValue();
				stateBuilder.append("\n").append(roomID).append(": ").append(String.join(",", occupants));
			}

		}

		return stateBuilder.toString();
	}

	public static String getRoomsFromName(String log, String token, String name, String role) throws Exception {
		String[] log_name = log.split("/");
		String log_file = log_name[log_name.length - 1];
		// TODO!
		// File file = new File("logs/" + log + "_dir/" + log_file);
		File file = new File(log_file);
		String existingData = readFromFile(file, token);

		Gson gson = new GsonBuilder().setPrettyPrinting().create();

		Type type = new TypeToken<Map<Integer, Map<String, String>>>() {
		}.getType();
		Map<Integer, Map<String, String>> existingMap = gson.fromJson(existingData, type);

		// Collect room entries in chronological order
		Map<Integer, Integer> roomEntries = new TreeMap<>();

		for (Map.Entry<Integer, Map<String, String>> entry : existingMap.entrySet()) {
			Map<String, String> id = entry.getValue();
			String entryName = id.get("name");
			String status = id.get("status");
			String roomIDStr = id.get("roomID");
			String event = id.get("event");
			Integer timestamp = entry.getKey();

			if (entryName.equals(name) && status.equals(role)) {
				if (event.equals("A") && !(Objects.equals(roomIDStr, "null"))) {
					roomEntries.put(timestamp, Integer.parseInt(roomIDStr));
				} else {
					roomEntries.remove(timestamp);
				}
			}
		}

		// Build the list of rooms in chronological order
		StringBuilder roomsBuilder = new StringBuilder();
		for (int roomID : roomEntries.values()) {
			if (roomsBuilder.length() > 0) {
				roomsBuilder.append(",");
			}
			roomsBuilder.append(roomID);
		}

		return roomsBuilder.toString();
	}

	private static String getTimeInGallery(String log, String token, String name, String role) {

		try {
			String[] log_name = log.split("/");
			String log_file = log_name[log_name.length - 1];
			// TODO!
			// File file = new File("logs/" + log + "_dir/" + log_file);
			File file = new File(log_file);
			String existingData = readFromFile(file, token);

			Gson gson = new GsonBuilder().setPrettyPrinting().create();

			Type type = new TypeToken<Map<Integer, Map<String, String>>>() {
			}.getType();
			Map<Integer, Map<String, String>> existingMap = gson.fromJson(existingData, type);

			// Collect room entries in chronological order

			int timeInGallery = 0;
			int arrival = 0;
			boolean inGallery = false;
			int currentTime = 0;

			for (Map.Entry<Integer, Map<String, String>> entry : existingMap.entrySet()) {
				Map<String, String> id = entry.getValue();
				String entryName = id.get("name");
				String status = id.get("status");
				String roomIDStr = id.get("roomID");
				String event = id.get("event");
				Integer timestamp = entry.getKey();
				currentTime = timestamp;
				if (entryName.equals(name) && status.equals(role)) {
					if (event.equals("A") && Objects.equals(roomIDStr, "null")) {
						arrival = timestamp;
						inGallery = true;
					} else if (event.equals("L") && Objects.equals(roomIDStr, "null")) {
						timeInGallery += timestamp - arrival;
						inGallery = false;
					}
				}
			}

			if (inGallery) {
				timeInGallery += currentTime - arrival;
			}
			if (timeInGallery > 0) {
				return String.valueOf(timeInGallery);
			}
			return "";
		} catch (Exception e) {
			// Handle exceptions appropriately
			return ""; // Return an empty string in case of an exception
		}
	}

	@Override
	public Integer call() throws Exception {

		// String[] log_name = log.split("/");
		// String log_file = log_name[log_name.length - 1];
		// File file = new File("logs/" + log + "_dir/" + log_file);
		// System.out.println(readFromFile(file, token));

		if (mode.getState) {
			System.out.println(getStateOfLog(log, token));
		} else if (mode.roomOrTime.options.getRooms) {
			System.out.println(
					getRoomsFromName(log, token, mode.roomOrTime.role.getName(), mode.roomOrTime.role.getStatus()));
		} else if (mode.roomOrTime.options.getTime) {
			System.out.println(
					getTimeInGallery(log, token, mode.roomOrTime.role.getName(), mode.roomOrTime.role.getStatus()));
		} else if (mode.roomOrTime.options.getRoomsOptional) {
			System.out.println("unimplemented");
		}
		return 0;
	}

	public static void main(String args[]) throws Exception {
		try {
			// NOTE This may not be the most elegant way to do this (parseArgs --> Execute)
			CommandLine cmd = new CommandLine(new LogRead());
			cmd.parseArgs(args);
			cmd.execute(args);
		} catch (Exception e) {
			// NOTE Maybe get rid of redundancy
			// TODO remove e.getMessage() when finished
			System.out.println("invalid");
			System.exit(255);
		}
	}
}
