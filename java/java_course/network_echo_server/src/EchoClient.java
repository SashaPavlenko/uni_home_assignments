import java.net.*;
import java.io.*;
import java.util.*;


public class EchoClient {
    private String addrIP;
    private int port;

    public EchoClient(String ip,int nPort){
      addrIP = ip;
      port = nPort;
    }

    public void tell() throws IOException {
// Passing null to getByName() returns the special
// "loopback" IP address, for testing on a single
// machine without a network
    InetAddress addr =
      InetAddress.getByName(addrIP);
// Alternatively you can use an address or a name:
// InetAddress addr = InetAddress.getByName("127.0.0.1");
// InetAddress addr = InetAddress.getByName("localhost");
    System.out.println("addr = " + addr);
    try(Socket socket = new Socket(addr, port)){
     boolean cont = true;
     Scanner input = new Scanner(System.in);
     try {
      System.out.println("socket = " + socket);
      Scanner sin = new Scanner(
          new InputStreamReader(socket.getInputStream()));
      PrintWriter sout = new PrintWriter( new BufferedWriter(
        new OutputStreamWriter(socket.getOutputStream())),true);
      while (cont) {
         String str = sin.nextLine();
         System.out.println(str);
         System.out.print(">>");
         String phrase = input.nextLine();
         sout.println(phrase);
         if (phrase.equals("BYE") )
           cont=false;
      }

    } finally {
      System.out.println("closing...");
       socket.close();
    }
  }
 }
public static void main(String[] args){
        try {
            EchoClient cl = new EchoClient("localhost",8189);
            cl.tell();
        } catch (IOException ex) {
            System.out.println("ERROR");
            ex.printStackTrace();
        }
}

}
