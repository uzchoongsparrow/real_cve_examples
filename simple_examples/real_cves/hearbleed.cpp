#include <iostream>
#include <cstring>
#include <vector>

class HeartbeatHandler {
public:
    HeartbeatHandler() {}

    bool validatePayloadLength(size_t length) {
        if (length > maxPayloadSize) {
            std::cout << "Invalid heartbeat payload length." << std::endl;
            return false;
        }
        return true;
    }

    void processHeartbeat(const char* payload, size_t length) {
        if (!validatePayloadLength(length)) {
            std::cout << "Heartbeat processing aborted." << std::endl;
            return;
        }

        vulnerableFunction(payload, length);
    }

private:
    static const size_t bufferSize = 1024;
    static const size_t maxPayloadSize = 2048;

    void vulnerableFunction(const char* heartbeatPayload, size_t payloadLength) {
        char buffer[bufferSize];
        if (payloadLength > bufferSize) {
            std::cout << "Payload too large, truncating." << std::endl;
            payloadLength = bufferSize;
        }

        // 잘못된 메모리 복사 발생
        memcpy(buffer, heartbeatPayload, payloadLength);

        // 클라이언트로 buffer를 보내는 것을 시뮬레이션
        std::cout << "Sending heartbeat response back." << std::endl;
    }
};

void simulateHeartbeat() {
    HeartbeatHandler handler;

    // 임의의 큰 데이터를 가진 하트비트 페이로드 시뮬레이션
    std::vector<char> heartbeatPayload(HeartbeatHandler::maxPayloadSize, 'A');

    std::cout << "Simulating Heartbleed vulnerability..." << std::endl;
    handler.processHeartbeat(heartbeatPayload.data(), heartbeatPayload.size());
}

int main() {
    simulateHeartbeat();
    return 0;
}
