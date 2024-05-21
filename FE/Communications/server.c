// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8888

int client_socket[2]; 
int connections = 0;  

void *connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    int other_sock = client_socket[0] == sock ? client_socket[1] : client_socket[0];
    int read_size, data_size;

    while(1) {
        // Read the size of the incoming screen data
        if ((read_size = recv(sock, &data_size, sizeof(data_size), 0)) > 0) {
            char* buffer = malloc(data_size);

            // Read the screen data itself
            read_size = recv(sock, buffer, data_size, 0);
            if (read_size > 0) {
                // Send it to the other client
                send(other_sock, buffer, data_size, 0);
            }

            free(buffer);
        }
        if (read_size == 0 || read_size == -1) break;
    }

    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    pthread_t sniffer_thread;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }

    listen(socket_desc, 2); 
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while(connections < 2) {
        printf("start\n");
        new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if (new_socket < 0) {
            perror("accept failed");
            return 1;
        }
        client_socket[connections++] = new_socket;
        // print current client's IP and port
        printf("Connection accepted from %d:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        if(pthread_create(&sniffer_thread, NULL, connection_handler, (void*)&client_socket[connections-1]) < 0) {
            perror("could not create thread");
            return 1;
        }
    }
    printf("Both clients connected. Starting game...\n");
    pthread_join(sniffer_thread, NULL);
    close(socket_desc);
    printf("Game over\n");
    return 0;
}