import java.io.*;
import java.net.*;
import java.util.*;
import org.json.*;
import org.apache.xerces.parsers.DOMParser;

class Server implements Runnable {
    private MulticastSocket socket;
    private final InetAddress group = InetAddress.getByName("ff12::caca");;
    private final int port = 6767;
    private int periodms = 1000;

    DOMParser parser = new DOMParser();

    private void sendBroadcast(String msg) throws IOException {
        byte[] buf = msg.getBytes();
        DatagramPacket p = new DatagramPacket(buf, buf.length, group, port);
        socket.send(p);
    }

    public Server(String ifname) throws IOException {
        socket = new MulticastSocket(port);
        socket.setReuseAddress(true);
        socket.bind(new InetSocketAddress(port));
        socket.setNetworkInterface(NetworkInterface.getByName(ifname));
    }

    @Override
    public void run() {
        byte[] buf = new byte[1024];
        while (true) {
            DatagramPacket p = new DatagramPacket(buf, buf.length);
            try { socket.receive(p); }
            catch (IOException e) { e.printStackTrace(); }
            String s = new String(p.getData(), 0, p.getLength());
            System.out.println("recv: " + s);
        }
    }

    public void sendLoop() {
        while (true) {
            try {
                sendBroadcast("test");
                System.out.println("sent");
            }
            catch (IOException e) { e.printStackTrace(); }

            try {
                Thread.sleep(periodms);
            } catch (Exception e) { e.printStackTrace(); }
        }
    }


    public static void main(String[] args) {
        System.out.println("pcc practica2 servidor mxn");

        try {
            Server s;
            if (args.length > 0)
                s = new Server(args[0]);
            else
                s =  new Server("lo");

            Thread st = new Thread(s);
            st.start();
            s.sendLoop();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

