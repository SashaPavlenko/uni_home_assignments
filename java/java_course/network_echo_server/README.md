# Network echo server

Client-server application over TCP sockets on port 8189.

- `EchoServer` - single-client server: greets the client and echoes every line back until it receives `BYE` (based on the example from Cay Horstmann's "Core Java")
- `MultiServer` + `ServerOneThread` - multithreaded server: accepts connections in a loop and serves every client in its own thread
- `EchoClient` - console client: prints the server's reply, sends the lines you type, `BYE` ends the session

```bash
javac -d out src/*.java
java -cp out MultiServer      # or EchoServer
java -cp out EchoClient       # in another terminal
```

The client connects to `localhost`; change the address in `EchoClient.main` to talk to a server on another machine.
