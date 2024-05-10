#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <ncursesw/curses.h>
#include <unistd.h>
#include <time.h>

//usage : gcc -o c 3.c -lncursesw

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

#define RED 1
#define GREEN 2
#define YELLOW 3

void init();
void printbox(int x, int y);

void printT(int x, int y); //박스가 시작하는 위치를 x, y로 받아서 그 위치에 출력할 수 있도록 / 함수 이름은 print{해당하는 자판}

int main() {
    init();

    attron(COLOR_PAIR(RED)); // 색상 적용
    attroff(COLOR_PAIR(RED)); // 원상복귀

    // 2,5부터 출력
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printbox(2+i*8,5+15*j);
            printR(2+i*8,5+15*j);
        }
    }

    // 사용자 입력 대기
    getch();

    // curses 종료
    endwin(); // curses 모드 종료

    return 0;

}

void init(){
    printf("\e[8;55;100t"); //창크기를 100*55로 설정

    // 환경 설정
    setlocale(LC_ALL, ""); // 유니코드 출력을 위해 로케일 설정
    
    // curses 초기화
    initscr(); // curses 모드 시작
    cbreak(); // 키 입력 버퍼 끄기
    noecho(); // 키 입력 반영 끄기
    keypad(stdscr, TRUE); // 특수 키 활성화
    curs_set(0); // 커서 숨기기
    start_color(); // 색상 사용 시작

    init_pair(1, COLOR_RED, COLOR_BLACK); // 빨간색 색상 페어 설정
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // 빨간색 색상 페어 설정
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // 빨간색 색상 페어 설정  
}

void printbox(int x, int y){
    move(x,y);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501" , 
    u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", 
    u8"\u2501", u8"\u2501", u8"\u2513"); // 특정 단어 출력
    
    for(int i=1;i<=6;i++){
        move(x+i,y);
        printw("%s             %s", u8"\u2503", u8"\u2503"); // 특정 단어 출력
    }
    move(x+7,y);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501" , 
    u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", 
    u8"\u2501", u8"\u2501", u8"\u251B"); // 특정 단어 출력
   
    // 화면 업데이트
    refresh();
}

void printT(int x, int y){
    move(x+1,y+1);
    printw("     %s%s%s",Quadrantlr,Full,Quadrantll);
    move(x+2,y+1);
    printw("    %s%s %s%s",Quadrantlr,Quadrantlrl,Quadrantlrr,Quadrantll);
    move(x+3,y+1);
    printw("   %s%s   %s%s",Quadrantlr,Quadrantlrl,Quadrantlrr,Quadrantll);
    move(x+4,y+1);
    printw("  %s%s     %s%s",Quadrantlr,Quadrantlrl,Quadrantlrr,Quadrantll);
    move(x+5,y+1);
    printw(" %s%s       %s%s",Quadrantlr,Quadrantlrl,Quadrantlrr,Quadrantll);
    move(x+6,y+1);
    printw("%s%s         %s%s",Quadrantlr,Quadrantlrl,Quadrantlrr,Quadrantll);
    refresh();
}