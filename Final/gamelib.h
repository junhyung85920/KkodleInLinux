#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncursesw/curses.h>
#include <time.h>
#include <unistd.h>
#include "errlib.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>


typedef enum {BLACK=0,RED,GREEN,YELLOW} Color;                               //문자 색상이 정의되어 있는 변수

typedef enum{R=20, S,E,F,A,Q,T,D,W,C,Z,X,V,G,K,I,J,U,H,Y,N,B,M,L} Word;                         //문자가 정의되어 있는 변수

void onGame(char* path, char* port);

int onStart();

void onHelp();

void onSuccess(int round);;

void onFail(Word answer[6]);

void onAnswer();

int isWord(char c);

char getWord(Word c);

Word inputWord(char c);
