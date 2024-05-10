
typedef enum {BLACK=0,RED,GREEN,YELLOW} Color;                               //문자 색상이 정의되어 있는 변수

typedef enum{R=20, S,E,F,A,Q,T,D,W,C,Z,X,V,G,K,I,J,U,H,Y,N,B,M,L} Word;                         //문자가 정의되어 있는 변수

int onGame(Word answer[6]);

int onStart();

void onHelp();

void onSuccess(int round);;

void onFail(Word answer[6]);