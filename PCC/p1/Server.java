import java.io.*;
import java.net.*;
import java.util.*;

class ServerThread implements Runnable {
    private Socket s;

    public ServerThread(Socket socket) {
        this.s = socket;
    }

    @Override
    public void run() {
        try {
            // create reader and writer
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);

            // parse request and print
            String[] requestLine = in.readLine().split(" ");
            String method = requestLine[0];
            String path = requestLine[1];
            String httpVer = requestLine[2];

            System.out.println(Arrays.toString(requestLine));

            // parse headers
            ArrayList<String[]> headers = new ArrayList<String[]>();
            String header = null;
            while ((header = in.readLine()) != null) {
                if (header.equals(""))
                    break;
                headers.add(header.split("\\s*:\\s*", 2));
            }

            // parse body
            ArrayList<String> body = new ArrayList<String>();
            if (method == "POST") {
                String bodyLine = null;
                while ((bodyLine = in.readLine()) != null) {
                    if (bodyLine.equals(""))
                        break;
                    body.add(bodyLine);
                }
            }

            // print them
            for (String[] h : headers) {
                System.out.println(h[0] + ": " + h[1]);
            }
            for (String s : body) {
                System.out.println(s);
            }


            // send response
            out.print("HTTP/1.1 200 OK\r\n");
            out.print("Connection: close\r\n");
            out.print("Server: PCC java shit/1\r\n");
            out.print("Set-Cookie: test=a;test2=b\r\n");
            out.print("Content-Type: text/html\r\n\r\n");
            out.print("<html><head></head><body>a</body></html>\r\n");
            out.flush();
            System.out.println("close");
            s.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


class Server {
    private Server() throws IOException {
        ServerSocket ss = new ServerSocket(8080);

        while (true) {
            Socket c = ss.accept();
            System.out.println("client accepted");

            ServerThread st = new ServerThread(c);
            Thread t = new Thread(st);
            t.start();
        }
    }


    public static void main(String[] args) {
        System.out.println("http server");

        try { new Server(); }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

