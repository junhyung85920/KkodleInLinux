
#include "gamelib.h"

#define Full u8"\u2588"
#define LowerHalf u8"\u2584"
#define UpperHalf u8"\u2580"
#define LeftHalf u8"\u258C"
#define RightHalf u8"\u2590"
#define Quadrantrlr u8"\u259F"
#define Quadrantllr u8"\u2599"
#define Quadrantlrl u8"\u259B"
#define Quadrantlrr u8"\u259C"
#define Quadrantll u8"\u2596"
#define Quadrantlr u8"\u2597"
#define Quadrantul u8"\u2598"
#define Quadrantur u8"\u259D"


void printWord(Word w, int row, int col);                  // round와 index에 해당하는 단어를 그림

void deleteWord(int round,int index);                               // round와 index에 해당하는 단어를 지움

void changeColor(Color check[],Word input[], int round);  // 색상을 변경

void printMainBackground(); // 백그라운드 그리기

void deleteRound(int round);

// void printR(int row, int col);  // ㄱ을 출력
// void printS(int row, int col);  // ㄴ을 출력
// void printE(int row, int col);  // ㄷ을 출력
// void printF(int row, int col);  // ㄹ을 출력
// void printA(int row, int col);  // ㅁ을 출력    
// void printQ(int row, int col);  // ㅂ을 출력
// void printT(int row, int col);  // ㅅ을 출력
// void printD(int row, int col);  // ㅇ을 출력
// void printW(int row, int col);  // ㅈ을 출력
// void printC(int row, int col);  // ㅊ을 출력
// void printZ(int row, int col);  // ㅋ을 출력
// void printX(int row, int col);  // ㅌ을 출력
// void printV(int row, int col);  // ㅍ을 출력
// void printG(int row, int col);  // ㅎ을 출력
// void printK(int row, int col);  // ㅏ을 출력
// void printI(int row, int col);  // ㅑ을 출력
// void printJ(int row, int col);  // ㅓ을 출력
// void printU(int row, int col);  // ㅕ을 출력
// void printH(int row, int col);  // ㅗ을 출력
// void printY(int row, int col);  // ㅛ을 출력
// void printN(int row, int col);  // ㅜ을 출력
// void printB(int row, int col);  // ㅠ을 출력
// void printM(int row, int col);  // ㅡ을 출력
// void printL(int row, int col);  // ㅣ을 출력
