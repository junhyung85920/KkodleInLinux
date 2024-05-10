#include <ncursesw/curses.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include "errlib.h"

void printWordError(){
    move(48,30);
    printw("잘못된 문자가 입력되었습니다");
    move(49,30);
    printw("입력 가능 문자 : ㄱ, ㄴ, ㄷ, ㄹ, ㅁ, ㅂ, ㅅ, ㅇ, ㅈ, ㅊ, ㅋ, ㅌ, ㅍ, ㅎ");
    refresh();
    usleep(1000000);
    flushinp();
    move(48,30);
    printw("                                                ");
    refresh();
}

void printLastError(){
    move(48,30);
    printw("마지막에는 Enter 혹은 Backspace를 눌러주세요");
    refresh();
    usleep(1000000);
    flushinp();
    move(48,30);
    printw("                                                 ");
    refresh();
}

void printFirstError(){
    move(48,30);
    printw("지울 수 있는 문자가 없습니다.");
    refresh();
    usleep(1000000);
    flushinp();
    move(48,30);
    printw("                                                 ");
    refresh();
}

void printEnterError(){
    move(48,30);
    printw("마지막에 Enter를 눌러주세요");
    refresh();
    usleep(1000000);
    flushinp();
    move(48,30);
    printw("                                            ");
    refresh();
}
