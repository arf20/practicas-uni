import java.io.*;
import java.net.*;
import java.util.*;

class Client {
    public static void main(String[] args) {
        try {
            // load cookies
            HashMap<String, String> cookies = new HashMap<String, String>();
            File cookieLoad = new File("cookies.txt");
            try (Scanner s = new Scanner(cookieLoad)) {
                while (s.hasNextLine()) {
                    String[] p = s.nextLine().split("=");
                    cookies.put(p[0], p[1]);
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

            // open socket, connect
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);
            // send request
            out.println("GET / HTTP/1.1");
            out.println("Host: " + args[0] + ":" + args[1]);
            out.println("User-Agent: pcc-client");
            out.println("Accept: */*");
            out.println("");

            // read response and parse headers and body
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));

            String[] responseLine = in.readLine().split(" ", 2);
            String httpVer = responseLine[0];
            String status = responseLine[1];

            System.out.println(Arrays.toString(responseLine));

            ArrayList<String[]> headers = new ArrayList<String[]>();
            String header = null;
            while ((header = in.readLine()) != null) {
                if (header.equals(""))
                    break;
                headers.add(header.split("\\s*:\\s*", 2));
            }

            ArrayList<String> body = new ArrayList<String>();
            String bodyLine = null;
            while ((bodyLine = in.readLine()) != null) {
                if (bodyLine.equals(""))
                    break;
                body.add(bodyLine);
            }

            // print headers and set cookies, print body
            for (String[] h : headers) {
                System.out.println(h[0] + ": " + h[1]);
                if (h[0].equals("Set-Cookie")) {
                    String[] resCookies = h[1].split("\\s*;\\s*");
                    for (String c : resCookies) {
                        String[] p = c.split("\\s*=\\s*");
                        cookies.put(p[0], p[1]);
                    }
                }
            }
            for (String b : body) {
                System.out.println(b);
            }

            // close socket and write out cookies
            s.close();

            FileWriter cookieStore = new FileWriter("cookies.txt");
            for (Map.Entry<String, String> c : cookies.entrySet())
                cookieStore.write(c.getKey() + "=" + c.getValue() + "\n");
            cookieStore.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

