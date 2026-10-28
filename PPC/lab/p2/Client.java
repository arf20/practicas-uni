import java.io.*;
import java.net.*;
import java.util.*;
import org.json.*;

class Client implements Runnable {
    private MulticastSocket socket;
    private final int port = 6767;
    private final InetSocketAddress group = new InetSocketAddress("ff12::caca", port);;
    private final NetworkInterface netif;

    private void sendUnicast(String host, String msg) throws IOException {
        byte[] buf = msg.getBytes();
        DatagramPacket p = new DatagramPacket(buf, buf.length, InetAddress.getByName(host), port);
        socket.send(p);
    }

    public Client(String ifname) throws IOException {
        socket = new MulticastSocket(port);
        socket.setReuseAddress(true);
        netif = NetworkInterface.getByName(ifname);
        socket.joinGroup(group, netif);
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


    public static void main(String[] args) {
        System.out.println("pcc practica2 cliente mxn");

        try {
            Client c;
            if (args.length > 0)
                c = new Client(args[0]);
            else
                c = new Client("lo");

            Thread st = new Thread(c);
            st.start();
            st.join();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


