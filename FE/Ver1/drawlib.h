

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

typedef enum {BLACK=0,RED,GREEN,YELLOW} Color;                               //문자 색상이 정의되어 있는 변수

typedef enum{R=20, S,E,F,A,Q,T,D,W,C,Z,X,V,G} Word;                         //문자가 정의되어 있는 변수

void printBox(int x, int y);                                        // 바탕 박스 그리기

void cleanBox(int x, int y);                                        // 박스 지우기

void printWord(Word w, int round, int index);                  // round와 index에 해당하는 단어를 그림

void deleteWord(int round,int index);                               // round와 index에 해당하는 단어를 지움

void changeColor(Color check[],Word input[], int round);  // 색상을 변경

Word inputWord(char c);    // 입력된 문자를 word로 변환

int isWord(char c); // 입력된 문자가 유효한 문자인지 확인

void printMainBackground(); // 백그라운드 그리기

//x, y는 상자의 좌측 최상단 좌표가 입력된다.
void printR(int x, int y);  //ㄱ 그리기

void printS(int x, int y);  //ㄴ 그리기

void printE(int x, int y);  //ㄷ 그리기

void printF(int x, int y);  //ㄹ 그리기

void printA(int x, int y);  //ㅁ 그리기

void printQ(int x, int y);  //ㅂ 그리기

void printT(int x, int y);  //ㅅ 그리기

void printD(int x, int y);  //ㅇ 그리기

void printW(int x, int y);  //ㅈ 그리기

void printC(int x, int y);  //ㅊ 그리기

void printZ(int x, int y);  //ㅋ 그리기

void printX(int x, int y);  //ㅌ 그리기

void printV(int x, int y);  //ㅍ 그리기

void printG(int x, int y);  //ㅎ 그리기

