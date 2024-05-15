#include <ncursesw/curses.h>
#include <locale.h>
#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "errlib.h"
#include "drawlib.h"

void printGgodle(){
    
}

void printStart(){

}

void printHemlp(){

}


int onStart(){
    clear();
    char c;
    int height, width;
    getmaxyx(stdscr, height, width); // 터미널의 크기를 얻어옴

    // 각 자모를 화면 중앙에 맞춰 출력
    int start_x = (width - (13 * 5)) / 2; // 5글자와 각 글자 사이의 간격 고려
    int start_y = (height - 7) / 2;       // 7은 각 자모가 차지하는 최대 높이

    // // 첫 번째 줄: ㅅ ㅣ ㅈ ㅏ ㄱ
    // printT(start_y, start_x);     // ㅅ
    // printL(start_y, start_x + 13); // ㅣ
    // printW(start_y, start_x + 26); // ㅈ
    // printK(start_y, start_x + 39); // ㅏ
    // printR(start_y, start_x + 52); // ㄱ

    // // 두 번째 줄: ㄷ ㅗ ㅇ ㅜ ㅁ
    // printE(start_y + 7, start_x);     // ㄷ
    // printH(start_y + 7, start_x + 13); // ㅗ
    // printD(start_y + 7, start_x + 26); // ㅇ
    // printN(start_y + 7, start_x + 39); // ㅜ
    // printA(start_y + 7, start_x + 52); // ㅁ

    while(1){
        c = getch();

        if(c == 'Q' || c == 'q'){
            return -1;
        }
        else if(c == 'H' || c == 'h'){
            return 0;
        }
        else if(c == 'S' || c == 's'){
            return 1;
        }
        else{
            printError("          Usage : Q,S,H");
        }
    }
    
}

