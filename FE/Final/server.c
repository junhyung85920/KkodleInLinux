#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CLIENTS 2
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
int int_values[MAX_CLIENTS];


// thread 실행 함수
void *handle_client(void *arg) {
    ClientData *client_data = (ClientData *)arg;
    int client_socket = client_data->socket;
    int index = client_data->index;
    int is_first_message = client_data->is_first_message;
    free(client_data);

    while (1) {
        if (is_first_message) {
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
            printf("Received word array from Client %d: ", index + 1);
            for (int i = 0; i < ARRAY_SIZE; i++) {
                printf("%d ", word_arrays[index][i]);
            }
            printf("\n");

            if (messages_received == MAX_CLIENTS) {
                // when two clients send word arrays
                for (int i = 0; i < MAX_CLIENTS; ++i) {
                    int other_index = (i + 1) % MAX_CLIENTS;
                    send(client_sockets[i], word_arrays[other_index], sizeof(word_arrays[other_index]), 0);
                    printf("Sent word array from Client %d to Client %d\n", other_index + 1, i + 1);
                }
                messages_received = 0; // init message count
                memset(word_arrays, 0, sizeof(word_arrays)); // init buffer(word)

                // is_first_message -> false로 설정 (다음 메시지부터는 int value를 받음)
                for (int i = 0; i < MAX_CLIENTS; ++i) {
                    client_data->is_first_message = 0;
                }
            }
            pthread_mutex_unlock(&lock);
        } else {
            int value;
            if (recv(client_socket, &value, sizeof(value), 0) <= 0) {
                printf("Client %d disconnected\n", index + 1);
                close(client_socket);
                pthread_mutex_lock(&lock);
                client_sockets[index] = 0;
                pthread_mutex_unlock(&lock);
                return NULL;
            }

            pthread_mutex_lock(&lock);
            int_values[index] = ntohl(value);
            printf("Received int value from Client %d: %d\n", index + 1, int_values[index]);
            messages_received++;

            if (messages_received == MAX_CLIENTS) {
                // when two clients send int values
                for (int i = 0; i < MAX_CLIENTS; ++i) {
                    int other_index = (i + 1) % MAX_CLIENTS;
                    int send_value = htonl(int_values[other_index]);
                    send(client_sockets[i], &send_value, sizeof(send_value), 0);
                    printf("Sent int value from Client %d to Client %d: %d\n", other_index + 1, i + 1, int_values[other_index]);
                }
                messages_received = 0; // init message count 
                memset(int_values, 0, sizeof(int_values)); // init buffer(int)
            }
            pthread_mutex_unlock(&lock);
        }
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // init array of client sockets
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        client_sockets[i] = 0;
    }

    // init mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }

    // socket fd 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // address struct 설정
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Waiting for clients...\n");

    while (1) {
        // accept clients
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&lock);

        // add new socket to array of client sockets if not full
        int i;
        for (i = 0; i < MAX_CLIENTS; ++i) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                printf("Client %d connected\n", i + 1);

                // client thread 생성
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
                    pthread_detach(thread_id); // 스레드가 종료 시 리소스 thread 해제
                }
                break;
            }
        }
        pthread_mutex_unlock(&lock);
    }




    close(server_fd);
    pthread_mutex_destroy(&lock);
    return 0;
}
