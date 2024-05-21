#include <ncursesw/curses.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include "errlib.h"

void printError(char* s){
    move(48,30);
    printw("%s",s);
    refresh();
    usleep(1000000);
    flushinp();
    move(48,30);
    printw("                                                 ");
    refresh();
}

void printWordError(){
    move(48,30);
    printw("잘못된 문자가 입력되었습니다");
    move(49,10);
    printw("입력 가능 문자 : ㄱ, ㄴ, ㄷ, ㄹ, ㅁ, ㅂ, ㅅ, ㅇ, ㅈ, ㅊ, ㅋ, ㅌ, ㅍ, ㅎ,");
    move(50,10);
    printw("                 ㅏ, ㅑ, ㅓ, ㅕ, ㅗ, ㅛ, ㅜ, ㅠ, ㅡ, ㅣ");
    refresh();
    usleep(1000000);
    flushinp();
    move(48,30);
    printw("                                                ");
    move(49,10);
    printw("                                                                         ");
    move(50,10);
    printw("                                                                         ");
    refresh();
}
