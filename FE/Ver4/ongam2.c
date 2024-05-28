

#include "drawlib.h"


int printMenu(int row, int col);


// Socket communication functions
int connectToServer(const char *server_ip, int server_port);
int sendAnswer(int sockfd, Word *answer);
int receiveAnswer(int sockfd, Word *answer);


void onGame(char *path)
{

    int menu = 0, opponent_result=2, count = 0, round = 0, result = -1;
    char c;
    Word *answer, *answer2;
    Word opponent_answer[6] = {D, K, S, S, U, D};
    Word opponent_answer2[6] = {Q,K,W,N,Z,K};

    int sockfd = -1;

    printMenu(16, 14);

    sockfd = connectToServer(path, 8888); // Replace with actual server IP and port
    if (sockfd < 0)
    {
        printError("Failed to connect to the server.");
        return;
    }

    sendAnswer(sockfd, opponent_answer);
    receiveAnswer(sockfd, answer);

    clear();
    for (int i = 0; i < 6; i++)
    {
        printWord(answer[i], 2 + 0 * 7, 6 + 13 * i);
    }

    sendAnswer(sockfd, opponent_answer2);
    receiveAnswer(sockfd, answer2);

    for (int i = 0; i < 6; i++)
    {
        printWord(answer2[i], 2 + 1 * 7, 6 + 13 * i);
    }
    getch();
    // close socket
    if (sockfd >= 0)
    {
        close(sockfd);
    }

    return;
}
int connectToServer(const char *server_ip, int server_port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    if (sockfd < 0)
    {
        perror("socket");
        return -1;
    }
   
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int sendAnswer(int sockfd, Word *answer)
{
    if (send(sockfd, answer, sizeof(Word) * 6, 0) < 0)
    {
        perror("send");
        return -1;
    }
    return 0;
}

int receiveAnswer(int sockfd, Word *answer)
{
    if (recv(sockfd, answer, sizeof(Word) * 6, 0) < 0)
    {
        printf("recv failed\n");
        perror("recv");
        return -1;
    }
    return 0;
}

/////////

int printMenu(int row, int col)
{
    clear();

    col += 7;

    move(row, col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
           u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2513");
    move(row + 1, col);
    printw("%s", u8"\u2503");
    move(row + 1, col + 47);
    printw("%s", u8"\u2503");
    move(row + 2, col);
    printw("%s", u8"\u2503");
    move(row + 2, col + 47);
    printw("%s", u8"\u2503");
    move(row + 3, col);
    printw("%s", u8"\u2503");
    move(row + 3, col + 47);
    printw("%s", u8"\u2503");
    move(row + 4, col);
    printw("%s", u8"\u2503");
    move(row + 4, col + 47);
    printw("%s", u8"\u2503");
    move(row + 5, col);
    printw("%s", u8"\u2503");
    move(row + 5, col + 47);
    printw("%s", u8"\u2503");

    printWord(A, row, col);
    printWord(J, row, col + 9);
    printWord(F, row, col + 20);
    printWord(X, row, col + 31);
    printWord(L, row, col + 39);

    move(row + 6, col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
           u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u251B");

    row += 16;
    col -= 7;

    move(row, col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
           u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2513");

    move(row + 1, col);
    printw("%s", u8"\u2503");
    move(row + 1, col + 62);
    printw("%s", u8"\u2503");
    move(row + 2, col);
    printw("%s", u8"\u2503");
    move(row + 2, col + 62);
    printw("%s", u8"\u2503");
    move(row + 3, col);
    printw("%s", u8"\u2503");
    move(row + 3, col + 62);
    printw("%s", u8"\u2503");
    move(row + 4, col);
    printw("%s", u8"\u2503");
    move(row + 4, col + 62);
    printw("%s", u8"\u2503");
    move(row + 5, col);
    printw("%s", u8"\u2503");
    move(row + 5, col + 62);
    printw("%s", u8"\u2503");

    printWord(T, row, col);
    printWord(L, row, col + 8);
    printWord(D, row, col + 16);
    printWord(R, row, col + 28);
    printWord(M, row, col + 39);
    printWord(F, row, col + 50);

    move(row + 6, col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
           u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u251B");
    refresh();

    char m;

    while (1)
    {
        m = getch();
        if (m == 'M' || m == 'm')
        {
            return 1;
        }
        else if (m == 'S' || m == 's')
        {
            return 0;
        }
        else
        {
            printError("Usage : multi is 'M', single is 'S'");
        }
    }
}
