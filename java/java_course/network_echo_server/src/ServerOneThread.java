import java.io.*;
import java.net.*;
/** Handles the server's communication with a single
client: runs it in its own thread and finishes it
after the client sends the end-of-session message
*/
public class ServerOneThread  extends Thread {
  private Socket socket;
  private BufferedReader in;
  private PrintWriter out;
  public ServerOneThread (Socket s) throws IOException {
    socket = s;// socket used to exchange data
    in = new BufferedReader(
        new InputStreamReader(socket.getInputStream()));
    out = new PrintWriter(
        new BufferedWriter(new OutputStreamWriter(
            socket.getOutputStream())), true);
// If any of the classes above throws an exception,
// the caller is responsible for closing the socket.
// Otherwise the thread will close it.
    start();
  }
  public void run() {
    try {
      out.println("Hello! Enter BYE to exit.");
      boolean done=true;
      while (done) {
        String str = in.readLine();
        if (str.equals("BYE")) {
               out.println("close");
               done=false;
        Thread.currentThread().interrupt();
        }
        else{
        System.out.println("Echoing: " + str);
        out.println("ECHO:"+str);}
      }
    } catch(IOException e) {
      System.err.println("IO Exception");
    } finally {
      try {
   System.out.println("closing...");
        socket.close();
      } catch(IOException e) {
        System.err.println("Socket not closed");
      }
    }
  }
}
