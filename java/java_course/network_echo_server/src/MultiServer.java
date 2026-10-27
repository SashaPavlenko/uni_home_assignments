import java.io.*;
import java.net.*;


  public class MultiServer {
  static final int PORT = 8189;
  public static void main(String[] args)throws IOException {
    ServerSocket s = new ServerSocket(PORT);
    System.out.println("Server Started");
    try {
      while(true) {
// Block until a new connection arrives:
        Socket socket = s.accept();
        try {
          new ServerOneThread(socket);
        } catch(IOException e) {
// On failure close the socket,
// otherwise the thread will close it:
          socket.close();
        }
      }
    } finally {

      s.close();
    }
  }
}
