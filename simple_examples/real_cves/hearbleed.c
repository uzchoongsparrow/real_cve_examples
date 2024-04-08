#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEARTBEAT_PAYLOAD_SIZE 2048
#define TRUE 1
#define FALSE 0

int validate_payload_length(int length) {
    // 페이로드 길이가 기대치를 초과하는지 검증
    if (length > HEARTBEAT_PAYLOAD_SIZE) {
        printf("Invalid heartbeat payload length.\n");
        return FALSE;
    }
    return TRUE;
}

void process_heartbeat(char *payload, int length) {
    if (!validate_payload_length(length)) {
        printf("Heartbeat processing aborted.\n");
        return;
    }

    // 취약한 함수 호출
    vulnerable_function(payload, length);
}

void vulnerable_function(char *heartbeat_payload, int payload_length) {
    char buffer[BUFFER_SIZE];
    if (payload_length > BUFFER_SIZE) {
        printf("Payload too large, truncating.\n");
        payload_length = BUFFER_SIZE;
    }

    // 잘못된 메모리 복사 발생
    memcpy(buffer, heartbeat_payload, payload_length);

    // 클라이언트로 buffer를 보내는 것을 시뮬레이션
    printf("Sending heartbeat response back.\n");
}

void simulate_heartbeat() {
    // 임의의 큰 데이터를 가진 하트비트 페이로드 시뮬레이션
    char *heartbeat_payload = malloc(HEARTBEAT_PAYLOAD_SIZE);
    memset(heartbeat_payload, 'A', HEARTBEAT_PAYLOAD_SIZE);

    // 고의적으로 BUFFER_SIZE보다 큰 payload_length를 사용하여 취약점을 시뮬레이션
    int payload_length = HEARTBEAT_PAYLOAD_SIZE;

    printf("Simulating Heartbleed vulnerability...\n");
    process_heartbeat(heartbeat_payload, payload_length);

    free(heartbeat_payload);
}

int main() {
    simulate_heartbeat();
    return 0;
}
