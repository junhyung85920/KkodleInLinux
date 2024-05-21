// client.c
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
//#include "drawlib.h"
#include "gamelib.h"


#define PORT 8888

void send_screen_data(int sock) {
    printf("Sending screen data\n");
    char screen_data[1024];  
    int data_size = sizeof(screen_data);
    strcpy(screen_data, "Simulated Screen Data");

    while (1) {
        send(sock, &data_size, sizeof(data_size), 0);
        send(sock, screen_data, data_size, 0);

        usleep(50000);  // Wait for 50ms to simulate delay between frames
    }
}

int main() {
    struct sockaddr_in serv_addr;
    int sock = 0;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    printf("Connected to server\n");
    //Word answer[6] = {E, K, F, L, A, L};
    //onGame(answer);

    system("./main");
    //send_screen_data(sock);  // Function to send screen data continuously

    close(sock);
    return 0;
}