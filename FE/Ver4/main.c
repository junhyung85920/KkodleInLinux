
#include "gamelib.h"


//usage : gcc -o main main.c draw.c ongame.c err.c onstart.c onhelp.c onfail.c onsuccess.c -lncursesw
//zip : zip pro.zip *
//transfer : multipass transfer pobi:/home/ubuntu/ELEC462/pro/pro.zip /Users/pobi/Downloads/pro.zip


void init();

int main() {
    
    init();
    int m = 1;

    while(1){
        m = onStart();
        if(m == -1){    //quit
            break;
        }
        else if(m == 0){    //help
            onHelp();
        }
        else{   //game
            onGame();
        }
    }
    
    clear();
    endwin(); // curses 모드 종료


    return 0;
}

void init(){
    printf("\e[8;55;90t"); //창크기를 90*55로 설정

    // 환경 설정
    setlocale(LC_ALL, ""); // 유니코드 출력을 위해 로케일 설정
    
    // curses 초기화
    initscr(); // curses 모드 시작
    cbreak(); // 키 입력 버퍼 끄기
    noecho(); // 키 입력 반영 끄기
    keypad(stdscr, TRUE); // 특수 키 활성화
    curs_set(0);
    start_color(); // 색상 사용 시작

    init_pair(RED, COLOR_RED, COLOR_BLACK); // 빨간색 색상 페어 설정
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK); // 초록색 색상 페어 설정
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK); // 노란색 색상 페어 설정
}


