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
//#include "gamelib.h"
//#include <ncursesw/curses.h>
#include "drawlib.h"

#define PORT 8888
#define HOSTLEN 256
#define BUFFER_SIZE 256
#define oops(msg) {perror(msg); exit(1);}

char getWord(Word c);

//Usage : gcc -o server server.c -lpthread

int client_sockets[2]; 
int connections = 0;  
int running = 1;

pthread_mutex_t lock;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    Word buffer_Word[BUFFER_SIZE];
    int buffer_Int;
    int round = -1;
    int bytes_received;
    
    int cnt = 0;
    while (1) { 
        printf("cnt: %d\n", cnt);
        if(cnt == 0){   // answer exchange
            if((bytes_received = recv(sock, buffer_Word, sizeof(buffer_Word) - 1, 0)) <= 0){
                //connections--;
                printf("current connections: %d\n", connections);
                perror("recv!");
                break;
            }
            pthread_mutex_lock(&lock);
            buffer_Word[bytes_received] = '\0';
            int other_sock = (sock == client_sockets[0]) ? client_sockets[1] : client_sockets[0];
            if (other_sock > 0) {
                printf("send to %d\n", other_sock);
                for (int i = 0; i < 6; i++)
                {
                    printf("%c", getWord(buffer_Word[i]));
                }
                printf("\n");
                
                if(send(other_sock, buffer_Word, sizeof(buffer_Word) - 1, 0) < 0){
                    perror("send failed!");
                    break;
                }
                printf("send success\n");
            }
            pthread_mutex_unlock(&lock);
        }

        else{   // result exchange
            if((bytes_received = recv(sock, &buffer_Int, sizeof(buffer_Int), 0)) <= 0){
                printf("current connections: %d\n", connections);
                perror("recv!");
                break;
            }
            pthread_mutex_lock(&lock);
            int other_sock = (sock == client_sockets[0]) ? client_sockets[1] : client_sockets[0];
            if (other_sock > 0) {
                printf("send to %d\n", other_sock);
                printf("result: %d\n", ntohl(buffer_Int));
                if(send(other_sock, &buffer_Int, sizeof(buffer_Int), 0) < 0){
                    perror("send failed!");
                    break;
                }
                printf("send success\n");
            }
            pthread_mutex_unlock(&lock);
        }

        cnt++;

        /*
        if (bytes_received == 0) {
            printf("Client disconnected\n");
            connections--;
            break;
        } else {
            perror("recv failed");
        }
        */
    }


    
    /*
    pthread_mutex_lock(&lock);
    for (int i = 0; i < connections; i++)
    {
        if (sock == client_sockets[i])
        {
        while (i++ < connections - 1) // 쓰레드 1개 삭제할 것이기 때문에 -1 해줘야 함
            client_sockets[i] = client_sockets[i + 1];
        break;
        }
    }
    connections--;
    pthread_mutex_unlock(&lock);
    */
    close(sock);
    running = 0;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c, connections = 0;
    struct sockaddr_in server, client;
    struct hostent *host;
    char hostname[HOSTLEN];
    pthread_t sniffer_thread;


    pthread_mutex_init(&lock, NULL);

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    bzero((void*)&server, sizeof(server));
    gethostname(hostname, HOSTLEN);
    printf("hostname: %s\n", hostname);
    host = gethostbyname(hostname);

    bcopy((void*)host->h_addr, (void*)&server.sin_addr, host->h_length);
    //server.sin_addr.s_addr = INADDR_ANY;
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
        //printf("here\n");
        client_sockets[connections++] = new_socket;
        printf("sockid: %d\n", new_socket);
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


char getWord(Word c)
{

    switch (c)
    {
    case R:
        return 'R';
    case S:
        return 'S';
    case E:
        return 'E';
    case F:
        return 'F';
    case A:
        return 'A';
    case Q:
        return 'Q';
    case T:
        return 'T';
    case D:
        return 'D';
    case W:
        return 'W';
    case C:
        return 'C';
    case Z:
        return 'Z';
    case X:
        return 'X';
    case V:
        return 'V';
    case G:
        return 'G';
    case K:
        return 'K';
    case I:
        return 'I';
    case J:
        return 'J';
    case U:
        return 'U';
    case H:
        return 'H';
    case Y:
        return 'Y';
    case N:
        return 'N';
    case B:
        return 'B';
    case M:
        return 'M';
    case L:
        return 'L';
    default:
        return 0;
    }
}