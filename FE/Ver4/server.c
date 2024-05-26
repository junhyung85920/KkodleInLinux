// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "gamelib.h"

#define PORT 8888
#define HOSTLEN 256
#define BUFFER_SIZE 7
#define oops(msg) {perror(msg); exit(1);}

int client_sockets[2]; 
int connections = 0;  
int running = 1;

pthread_mutex_t lock;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    Word buffer[BUFFER_SIZE];
    int round = -1;
    int bytes_received;
    
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';

        pthread_mutex_lock(&lock);
        int other_sock = (sock == client_sockets[0]) ? client_sockets[1] : client_sockets[0];
        if (other_sock > 0) {
            send(other_sock, buffer, bytes_received, 0);
        }
        pthread_mutex_unlock(&lock);

        if (bytes_received == 0) {
            printf("Client disconnected\n");
            connections--;
            break;
        } else {
            perror("recv failed");
        }
    }

    close(sock);
    running = 0;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c, connections = 0;
    struct sockaddr_in server, client;
    struct hostent *host;
    Word hostname[HOSTLEN];
    pthread_t sniffer_thread;


    pthread_mutex_init(&lock, NULL);

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    bzero((void*)&server, sizeof(server));
    gethostname(hostname, HOSTLEN);
    host = gethostbyname(hostname);

    bcopy((void*)host->h_addr, (void*)&server.sin_addr, host->h_length);
    // server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);


    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) != 0) {
        oops("bind");
    }

    // Listen
    if(listen(socket_desc, 2) != 0) {
        oops("listen");
    }

    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    printf("start\n");
    // Accept and incoming connection
    while(running) {
        printf("current connections: %d\n", connections);
        new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if (new_socket < 0) {
            oops("accept");
        }
        printf("here\n");
        client_sockets[connections++] = new_socket;
        // print current client's IP and port
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        if(pthread_create(&sniffer_thread, NULL, handle_client, (void*)&client_sockets[connections-1]) < 0) {
            oops("could not create thread");
        }

        if(connections == 2) {
            printf("current connections: %d\n", connections);
            printf("Both clients connected. Starting game...\n");
            pthread_join(sniffer_thread, NULL);
        }
        
    }
    pthread_mutex_destroy(&lock);
    close(socket_desc);
    printf("Game over\n");
    return 0;
}