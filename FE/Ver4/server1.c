#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CLIENTS 2
#define BUFFER_SIZE 1024
#define ARRAY_SIZE 6

typedef enum {
    R = 20, S, E, F, A, Q, T, D, W, C, Z, X, V, G, K, I, J, U, H, Y, N, B, M, L
} Word;

typedef struct {
    int socket;
    int index;
    int is_first_message;
} ClientData;

int client_sockets[MAX_CLIENTS];
pthread_mutex_t lock;
int messages_received = 0;
Word word_arrays[MAX_CLIENTS][ARRAY_SIZE];

void *handle_client(void *arg) {
    ClientData *client_data = (ClientData *)arg;
    int client_socket = client_data->socket;
    int index = client_data->index;
    int is_first_message = client_data->is_first_message;
    free(client_data);

    while (1) {
        Word buffer[ARRAY_SIZE];
        memset(buffer, 0, sizeof(buffer));

        if (recv(client_socket, buffer, sizeof(buffer), 0) <= 0) {
            printf("Client %d disconnected\n", index + 1);
            close(client_socket);
            pthread_mutex_lock(&lock);
            client_sockets[index] = 0;
            pthread_mutex_unlock(&lock);
            return NULL;
        }

        pthread_mutex_lock(&lock);
        memcpy(word_arrays[index], buffer, sizeof(buffer));
        messages_received++;

        if (messages_received == MAX_CLIENTS) {
            // 모든 클라이언트로부터 배열을 받았을 때
            for (int i = 0; i < MAX_CLIENTS; ++i) {
                int other_index = (i + 1) % MAX_CLIENTS;
                send(client_sockets[i], word_arrays[other_index], sizeof(word_arrays[other_index]), 0);
            }
            messages_received = 0; // 메시지 수신 카운트 초기화
            is_first_message = 0; // 다음 메시지도 배열을 받도록 설정
            memset(word_arrays, 0, sizeof(word_arrays)); // 배열 초기화
        }
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // 클라이언트 소켓 배열 초기화
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        client_sockets[i] = 0;
    }

    // 뮤텍스 초기화
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }

    // 소켓 파일 디스크립터 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 주소 구조체 설정
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 소켓에 주소 바인딩
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 수신 대기 모드 설정
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Waiting for clients...\n");

    while (1) {
        // 새 클라이언트 연결 수락
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // 뮤텍스 잠금
        pthread_mutex_lock(&lock);

        // 빈 슬롯 찾기
        int i;
        for (i = 0; i < MAX_CLIENTS; ++i) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                printf("Client %d connected\n", i + 1);
                break;
            }
        }

        // 클라이언트 슬롯이 꽉 찬 경우
        if (i == MAX_CLIENTS) {
            printf("Server is full. Rejecting client.\n");
            close(new_socket);
        } else {
            // 클라이언트 처리 스레드 생성
            pthread_t thread_id;
            ClientData *client_data = (ClientData *)malloc(sizeof(ClientData));
            client_data->socket = new_socket;
            client_data->index = i;
            client_data->is_first_message = 1;

            if (pthread_create(&thread_id, NULL, handle_client, (void *)client_data) != 0) {
                perror("pthread_create");
                close(new_socket);
                client_sockets[i] = 0;
                free(client_data);
            } else {
                pthread_detach(thread_id); // 스레드가 종료되면 리소스 자동 회수
            }
        }

        // 뮤텍스 잠금 해제
        pthread_mutex_unlock(&lock);
    }

    close(server_fd);
    pthread_mutex_destroy(&lock);
    return 0;
}
