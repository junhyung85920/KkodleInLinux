#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 64
#define MAX_PLAYERS_PER_GAME 2
#define MAX_GAME_NUM MAX_PLAYERS / 2
#define ARRAY_SIZE 6

typedef enum {
    R = 20, S, E, F, A, Q, T, D, W, C, Z, X, V, G, K, I, J, U, H, Y, N, B, M, L
} Word;

typedef struct {
    int socket;
    int index;
    int game_num;
} ClientData;

int client_sockets[MAX_PLAYERS];
pthread_mutex_t lock;
int messages_received[MAX_GAME_NUM];
Word word_arrays[MAX_GAME_NUM][MAX_PLAYERS][ARRAY_SIZE];
int int_values[MAX_GAME_NUM][MAX_PLAYERS];
int current_players = 0;



// thread 실행 함수
void *handle_client(void *arg) {
    ClientData *client_data = (ClientData *)arg;
    int client_socket = client_data->socket;
    int index = client_data->index;     // index + 1 -> client number
    int opponent;
    int game_num = client_data->game_num;
    free(client_data);
    
    
    if((index % 2) == 0){
        opponent = index + 1;
    }
    else{
        opponent = index - 1;
    }

    while (1) {
        Word buffer[ARRAY_SIZE];
        memset(buffer, 0, sizeof(buffer));

        if (recv(client_socket, buffer, sizeof(buffer), 0) <= 0) {
            printf("\nClient %d disconnected\n", index + 1);
            current_players--;
            printf("\ncurrent_players: %d\n", current_players);
            close(client_socket);
            pthread_mutex_lock(&lock);
            client_sockets[index] = 0;
            pthread_mutex_unlock(&lock);
            return NULL;
        }
        pthread_mutex_lock(&lock);
        memcpy(word_arrays[game_num][index], buffer, sizeof(buffer));
        messages_received[game_num]++;
        printf("\n(Room %d) : Received information from Client %d", game_num, index + 1);
        printf("\n");

        if (messages_received[game_num] == MAX_PLAYERS_PER_GAME) {
            // when two clients send word arrays
            send(client_sockets[index], word_arrays[game_num][opponent], sizeof(word_arrays[game_num][opponent]), 0);
            send(client_sockets[opponent], word_arrays[game_num][index], sizeof(word_arrays[game_num][index]), 0);
            printf("\n(Room %d) : exchanged information ( Client %d & Client %d )\n", game_num, opponent + 1, index + 1);
            
            messages_received[game_num] = 0; // init message count
            memset(word_arrays[game_num][index], 0, sizeof(word_arrays[game_num][index])); // init buffer(index)
            memset(word_arrays[game_num][opponent], 0, sizeof(word_arrays[game_num][opponent])); // init buffer(opponent)
        }
        pthread_mutex_unlock(&lock);

    }
}

int main(int argc, char* argv[]) {
    if(argc != 2){
        printf("Usage : %s [port]\n", argv[0]);
        return 0;
    }
    int server_fd, new_socket, port_num = atoi(argv[1]);
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // init num of message_received
    for(int i = 0; i < MAX_GAME_NUM; i++){
        messages_received[i] = 0;
    }

    // init array of client sockets
    for (int i = 0; i < MAX_PLAYERS; ++i) {
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
    address.sin_port = htons(port_num);

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
        current_players++;
        printf("\ncurrent_players: %d\n", current_players);

        // add new socket to array of client sockets if not full
        int i, j;
        
        for (i = 0; i < MAX_PLAYERS; ++i) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;

                // client thread 생성
                pthread_t thread_id;
                ClientData *client_data = (ClientData *)malloc(sizeof(ClientData));
                client_data->socket = new_socket;
                client_data->index = i;
                client_data->game_num = ((current_players - 1) / 2) + 1;  // 게임방 번호 부여
                printf("\nClient %d connected in (Room %d)\n", i + 1, client_data->game_num);

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
