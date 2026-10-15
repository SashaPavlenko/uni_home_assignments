package l_append;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;
import picocli.CommandLine;
import picocli.CommandLine.ArgGroup;
import picocli.CommandLine.Command;
import picocli.CommandLine.Option;
import picocli.CommandLine.Parameters;

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.lang.reflect.Type;
import java.security.SecureRandom;
import java.util.*;
import java.util.concurrent.Callable;

@Command(name = "LogAppend")
class LogAppend implements Callable<Integer> {
	// parseCommandLineArguments

	@ArgGroup(exclusive = true, multiplicity = "1")
	Mode mode;

	static class Mode {
		@Option(names = { "-B", "--batch" }, description = "Batch file of commands")
		String batchFile;

		@ArgGroup(exclusive = false)
		Single single;

		static class Single {
			// Check if Timestamp is a non-negative integer (ranging from 0 to 1073741823
			// inclusively)
			int timestamp;

			@Option(names = { "-T", "--timestamp" }, description = "Time the event is recorded.", required = true)
			public void ValidateTimestampForm(int value) {
				if (value >= 0 && value <= 1073741823) {
					timestamp = value;
				} else {
					System.out.println("invalid");
					System.exit(255);
				}
			}

			// Check if Token consists of an arbitrary-sized string of alphanumeric (a-z,
			// A-Z, and 0-9) characters
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

			// Check if names only contain letters + no spaces
			@ArgGroup(exclusive = true, multiplicity = "1")
			Role role;

			static class Role {
				String employeeName;

				@Option(names = { "-E", "--employee" }, description = "Employee name.")
				public void ValidateEmployeeNameForm(String value) {
					if (value.matches("[a-zA-Z]+")) {
						employeeName = value;
					} else {
						System.out.println("invalid");
						System.exit(255);
					}
				}

				String guestName;

				@Option(names = { "-G", "--guest" }, description = "Guest name.")
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
						// System.out.println(employeeName + " " + guestName);
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

			@ArgGroup(exclusive = true, multiplicity = "1")
			Event event;

			static class Event {
				@Option(names = { "-A", "--arrival" }, description = "Guest arrival.")
				boolean isArrival;

				@Option(names = { "-L", "--departure" }, description = "Guest departure.")
				boolean isDeparture;
			}

			// Check if roomID is a non-negative integer characters with no spaces (ranging
			// from 0 to 1073741823 inclusively)
			// No leading zeros in integers
			Integer roomID;

			@Option(names = { "-R", "--room" }, description = "Room ID.")
			public void ValidateRoomIDForm(int value) {
				if (value >= 0 && value <= 1073741823) {
					roomID = value;
				} else {
					System.out.println("invalid");
					System.exit(255);
				}
			}

			// NOTE Trailing slashes in logs are invalid. Maybe change that
			private String log;

			@Parameters(index = "0", description = "Path to the log file.")
			public void ValidateLogForm(String value) {
				if (value.matches("^[a-zA-Z0-9_\\./]+[^/]+$")) {
					log = value;
				} else {
					System.out.println("invalid");
					System.exit(255);
				}
			}

		}
	}

	private static byte[] getBytesFromString(String string) {
		String[] strings = string.replace("[", "").replace("]", "").split(", ");
		byte result[] = new byte[strings.length];
		for (int i = 0; i < result.length; i++) {
			result[i] = Byte.parseByte(strings[i]);
		}
		return result;
	}

	public static void generateSaltAndIV(File file) throws Exception {
		SecureRandom SecRan = new SecureRandom();

		byte[] salt = new byte[16];
		SecRan.nextBytes(salt);

		byte[] iv = new byte[16];
		SecRan.nextBytes(iv);

		BufferedWriter writer = new BufferedWriter(new FileWriter(file));

		writer.write(Arrays.toString(salt));
		writer.newLine();
		writer.write(Arrays.toString(iv));

		writer.close();
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
		// NOTE If we get problems with runtime, we could reduce the iteration count
		PBEKeySpec spec = new PBEKeySpec(token.toCharArray(), salt, 100, 256);
		SecretKey secret = new SecretKeySpec(factory.generateSecret(spec).getEncoded(), "AES");
		return secret;
	}

	private static String encryptData(String data, SecretKey secretKey, IvParameterSpec iv) throws Exception {
		Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

		// Use the secret key from the token
		cipher.init(Cipher.ENCRYPT_MODE, secretKey, iv);

		byte[] encryptedBytes = cipher.doFinal(data.getBytes());
		return Base64.getEncoder().encodeToString(encryptedBytes);
	}

	private static String decryptData(String data, SecretKey secretKey, IvParameterSpec iv) throws Exception {
		byte[] decryptedBytes = {};
		try {
			Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

			// Use the secret key from the token
			cipher.init(Cipher.DECRYPT_MODE, secretKey, iv);

			byte[] decodedBytes = Base64.getDecoder().decode(data);
			decryptedBytes = cipher.doFinal(decodedBytes);
		} catch (Exception e) {
			System.out.println("invalid");
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

	private static void writeJSONToFile(String jsonData, File file, String token) throws Exception {
		writeJSONToFile(jsonData, file, token, false);
	}
	private static void writeJSONToFile(String jsonData, File file, String token, boolean rewrite) throws Exception {
		BufferedWriter writer;
		if (rewrite) {
			// If rewrite is true, create a new file and write the encrypted data
			writer = new BufferedWriter(new FileWriter(file));
		} else {
			// If rewrite is false, append the encrypted data to the existing file
			writer = new BufferedWriter(new FileWriter(file, true));
		}

		// encrypting data
		// Use the token from command
		File file_config = new File(file + "_config");
		byte[] salt = getSalt(file_config);
		SecretKey secretKey = getSecretKeyFromToken(token, salt);

		IvParameterSpec iv = getIV(file_config);

		String encryptedData = encryptData(jsonData, secretKey, iv);

		writer.write(encryptedData);
		writer.close();
	}

	public void writeToLog() throws Exception {
		int id = mode.single.timestamp;

		String token = mode.single.token;
		String event = mode.single.event.isArrival ? "A" : "L";
		String status = mode.single.role.getStatus();
		String name = mode.single.role.getName();
		String roomID = String.valueOf(mode.single.roomID);
		String log = mode.single.log;

		Map<String, String> dataId = new HashMap<>();
		dataId.put("token", token);
		dataId.put("event", event);
		dataId.put("status", status);
		dataId.put("name", name);
		dataId.put("roomID", roomID);

		Map<Integer, Map<String, String>> data = new HashMap<>();
		data.put(id, dataId);

		String status_letter = mode.single.role.getStatus().equals("employee") ? "E" : "G";
		String roomID_letter = !roomID.equals("null") ? " -R " + roomID : "";

		ArrayList<LogAppend> oneItemArray = new ArrayList<>();
		String line = String.format("-T %s -K %s -%s %s -%s%s %s", id, token, status_letter, name, event, roomID_letter, log);
		String[] newArgs = line.replace("\n\n", "\n").split(" ");
		LogAppend logappend = new LogAppend();
		CommandLine cmd = new CommandLine(logappend);
		cmd.parseArgs(newArgs);

		if (logappend.mode.batchFile == null) {
			oneItemArray.add(logappend);
		} else {
			System.out.println("invalid");
		}

		writeToLog(oneItemArray);
	}

	public static void writeToLog(ArrayList<LogAppend> logAppendArrayList) throws Exception {
		Type type = new TypeToken<Map<Integer, Map<String, String>>>() {
		}.getType();
		Map<Integer, Map<String, String>> existingMap = null;

		Map<String, Map<Integer, Map<String, String>>> mapsForLogs = new HashMap<>();
		Map<String, String> logs_to_token = new HashMap<>();
		for (int i = 0; i < logAppendArrayList.size(); ++i) {
			LogAppend curr_logAppend = logAppendArrayList.get(i);
			String token = curr_logAppend.mode.single.token;
			String log = curr_logAppend.mode.single.log;

			String[] log_name = log.split("/");
			String log_file = log_name[log_name.length - 1];

			// TODO make only once read decryption per each logs
			if (mapsForLogs.get(log) == null) {
				File file = new File(log_file);
				File file_config = new File(log_file + "_config");
				Gson gson = new GsonBuilder().setPrettyPrinting().create();

				if (file.exists()) {
//					generateSaltAndIV(file_config);

					String existingData = readFromFile(file, token);
					existingMap = gson.fromJson(existingData, type);
					logs_to_token.put(log, token);
					mapsForLogs.put(log, existingMap);
					logs_to_token.put(log, token);
				} else {
					mapsForLogs.put(log, null);
					logs_to_token.put(log, null);
				}
			}
		}


		for (int curr_append_index = 0; curr_append_index < logAppendArrayList.size(); ++curr_append_index) {
			LogAppend curr_logAppend = logAppendArrayList.get(curr_append_index);

			int id = curr_logAppend.mode.single.timestamp;

			String token = curr_logAppend.mode.single.token;
			String event = curr_logAppend.mode.single.event.isArrival ? "A" : "L";
			String status = curr_logAppend.mode.single.role.getStatus();
			String name = curr_logAppend.mode.single.role.getName();
			String roomID = String.valueOf(curr_logAppend.mode.single.roomID);
			String log = curr_logAppend.mode.single.log;
			existingMap = mapsForLogs.get(log);

			Map<String, String> dataId = new HashMap<>();
			dataId.put("token", token);
			dataId.put("event", event);
			dataId.put("status", status);
			dataId.put("name", name);
			dataId.put("roomID", roomID);

			Map<Integer, Map<String, String>> data = new HashMap<>();
			data.put(id, dataId);

			// Convert data to JSON format
			Gson gson = new GsonBuilder().setPrettyPrinting().create();
			String jsonData = gson.toJson(data);

			// Check for and handle file existence
			// Use the in the command provided file

			// In case log is a path to the log file

			// TODO! Debug code: Code commended Out for debug purposes
			// String[] log_name = log.split("/");
			// String log_file = log_name[log_name.length - 1];
			//
			// File dir = new File("logs/" + log + "_dir/");
			// File file = new File("logs/" + log + "_dir/" + log_file);
			//
			// // TODO maybe delete the dir and file if the command was invalid
			// if (dir.mkdirs() || file.createNewFile()) {

			String[] log_name = log.split("/");
			String log_file = log_name[log_name.length - 1];

			File file = new File(log_file);
			File file_config = new File(log_file + "_config");

			// TODO maybe delete the dir and file if the command was invalid
			if (file.createNewFile()) {

				// File was created
				if (!(event.equals("A") && Objects.equals(roomID, "null"))) {
					System.out.println("invalid");
					System.exit(255);
					// throw new Exception("Incorrect action. When person is out of the gallery then
					// they is available only enter to the gallery.");
				}
				// TODO!
				// File file_config = new File("logs/" + log + "_dir/" + log_file + "_config");

				if (!file_config.exists())
					generateSaltAndIV(file_config);
				writeJSONToFile(jsonData, file, curr_logAppend.mode.single.token);


//				String existingData = readFromFile(file, token);
				existingMap = gson.fromJson(jsonData, type);
				mapsForLogs.put(log, existingMap);
				logs_to_token.put(log, token);
			} else {
				// File already exists
//				String existingData = readFromFile(file, token);
//				if (existingMap == null) {
//					// File is empty
//					writeJSONToFile(jsonData, file, curr_logAppend.mode.single.token);
//					existingMap = gson.fromJson(existingData, type);
//					logs_to_token.put(log, token);
//				} else {
					// File is not empty
//					if (existingMap == null) {
//						existingData = readFromFile(file, token);
//						existingMap = gson.fromJson(existingData, type);
//					}

					// Check if current info could be added regarding IDs.
					for (int key : existingMap.keySet()) {
						if (id <= key) {
							System.out.println("invalid");
							System.exit(255);
						}
					}

					List<Integer> keys = new ArrayList<>(existingMap.keySet());
					keys.sort(Comparator.naturalOrder());

					int i = existingMap.size() - 1;
					while ((i >= 0) &&
							!((existingMap.get(keys.get(i)).get("name").equals(name)) &&
									(existingMap.get(keys.get(i)).get("status").equals(status))))
						--i;

					// Case when person was already added to log file. We assume that if we added
					// info about this person,
					// so we can assume that the whole info in log file is all correct, and now we
					// have to only check if
					// current info that we're planning to add is correct.
					if (i != -1) {
						// Case when person had entered the gallery.
						if (Objects.equals(existingMap.get(keys.get(i)).get("roomID"), "null")) {
							if (existingMap.get(keys.get(i)).get("event").equals("A")) {
								if (!((event.equals("A") && !Objects.equals(roomID, "null"))
										|| (event.equals("L") && Objects.equals(roomID, "null")))) {
									System.out.println("invalid");
									System.exit(255);
									// throw new Exception("Incorrect action. When person arrived to the gallery
									// then they is available only enter any room or exit gallery.");
								}
							}
						}

						// Case when person had exited the gallery.
						if (Objects.equals(existingMap.get(keys.get(i)).get("roomID"), "null")) {
							if (existingMap.get(keys.get(i)).get("event").equals("L")) {
								if (!(event.equals("A") && Objects.equals(roomID, "null"))) {
									System.out.println("invalid");
									System.exit(255);
									// throw new Exception("Incorrect action. When person is out of the gallery then
									// they is available only enter to the gallery.");
								}

							}
						}

						// Case when person had entered to the specific room.
						if (!Objects.equals(existingMap.get(keys.get(i)).get("roomID"), "null")) {
							if (existingMap.get(keys.get(i)).get("event").equals("A")) {
								if (!(event.equals("L") && !Objects.equals(roomID, "null")
										&& roomID.equals(existingMap.get(keys.get(i)).get("roomID")))) {
									System.out.println("invalid");
									System.exit(255);
									// throw new Exception("Incorrect action. When person had entered to the
									// specific room then they is available only exit this room.");
								}

							}
						}

						// Case when person had exited a room.
						if (!Objects.equals(existingMap.get(keys.get(i)).get("roomID"), "null")) {
							if (existingMap.get(keys.get(i)).get("event").equals("L")) {
								if (!((event.equals("A") && !Objects.equals(roomID, "null"))
										|| (event.equals("L") && Objects.equals(roomID, "null")))) {
									System.out.println("invalid");
									System.exit(255);
									// throw new Exception("Incorrect action. When person had exited a room then
									// they is available only enter a room or exit the gallery.");
								}

							}
						}

					} else {
						// Case when person was never added to log file, the person first has to enter
						// the gallery
						if (!(event.equals("A") && Objects.equals(roomID, "null"))) {
							System.out.println("invalid");
							System.exit(255);
							// throw new Exception("Incorrect action. When person is out of the gallery then
							// they is available only enter to the gallery.");
						}
					}

					// Add new data to existing
					existingMap.putAll(data);
					mapsForLogs.put(log, existingMap);

					logs_to_token.put(log, token);
//					System.out.println(mapsForLogs);
				}

			}
//		}

		Gson gson = new GsonBuilder().setPrettyPrinting().create();

		for (String log:
			 logs_to_token.keySet()) {
			String[] log_name = log.split("/");
			String log_file = log_name[log_name.length - 1];

			File file = new File(log_file);
			String updatedData = gson.toJson(mapsForLogs.get(log));
			writeJSONToFile(updatedData, file, logs_to_token.get(log), true);
		}

	}

	public void writeMultipleEntriesToLog() throws Exception {
		// TODO
	}



	// TODO add a batch update( If secret and log in lines are the same, update them
	// at once and not do encryption+decryption for every line)
	public void readFromBatchFile() throws Exception {
		// No -B in batch file.
		BufferedReader br = new BufferedReader(new FileReader(mode.batchFile));
		String line;

		ArrayList<LogAppend> logAppendArrayList = new ArrayList<>();
		while ((line = br.readLine()) != null) {
			try {
				if (!line.isEmpty()) {
					String[] newArgs = line.replace("\n\n", "\n").split(" ");
					// TODO maybe change out logappend to this for performance
					LogAppend logappend = new LogAppend();
					CommandLine cmd = new CommandLine(logappend);
					cmd.parseArgs(newArgs);

					if (logappend.mode.batchFile == null) {
						// TODO
						logAppendArrayList.add(logappend);
						// writeMultipleEntriesToLog();
//						cmd.execute(newArgs);
					} else {
						System.out.println("invalid");
					}
				}
			} catch (Exception e) {
				System.out.println("invalid");
			}
		}
		call(logAppendArrayList);
		br.close();
	}

	@Override
	public Integer call() throws Exception {
		if (mode.batchFile == null) {
			writeToLog();
		} else if (mode.batchFile.isEmpty()) {
			System.out.println("invalid");
		} else {
			readFromBatchFile();
		}
		return 0;
	}

	public Integer call(ArrayList<LogAppend> logAppendArrayList) throws Exception {
		writeToLog(logAppendArrayList);
		return 0;
	}

	public static void main(String... args) {
		try {
			// Debug code:
			// System.out.println(Arrays.toString(args));
			// try {
			// System.out.println("batch:" +
			// Files.readString(Path.of("/home/ubuntu/batch64")));
			// System.out.println("script:" +
			// Files.readString(Path.of("/home/ubuntu/scriptB64")));
			// } catch (Throwable ignored) {
			// }

			// NOTE This may not be the most elegant way to do this (parseArgs --> Execute)
			CommandLine cmd = new CommandLine(new LogAppend());
			cmd.parseArgs(args);
			cmd.execute(args);

		} catch (Exception e) {
			// NOTE Maybe get rid of redundancy
			System.out.println("invalid");
			System.exit(255);
		}

	}
}
