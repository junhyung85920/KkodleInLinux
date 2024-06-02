
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

void deleteRound(int round); // round에 해당하는 단어를 지움
