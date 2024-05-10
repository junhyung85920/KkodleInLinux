#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <ncursesw/curses.h>
#include <unistd.h>
#include "drawlib.h"
#include "errlib.h"

//usage : gcc -o main main.c draw.c err.c -lncursesw


void init();

void changeColor(Color check[],Word input[], int round);

int main() {
    init();
    
    printMainBackground();

    Color after[6] = {RED,RED,GREEN,RED,YELLOW,RED};

    for(int i=0;i<6;i++){
        Word w[6];
        int count=0;
        while(count<=6){
            char c = getch();
            if((c=='\n'||c=='\r'||c==KEY_ENTER)&&count==6){
                break;
            }
            else if(c==7 || c==KEY_BACKSPACE){
                if(count==0){
                    printFirstError();
                }
                else{
                    deleteWord(i,--count);
                }
            }
            else if(isWord(c)){
                if(count==6){
                    printWordError();
                }
                else{
                    w[count] = inputWord(c);
                    printWord(w[count],i,count++);
                }
            }
        }

        changeColor(after,w,i);

    }

    //usleep(5000000);

    // curses 종료
    endwin(); // curses 모드 종료


    return 0;
}

void changeColor(Color check[], Word input[], int round){
    for(int i=0;i<6;i++){
        if(check[i]==GREEN){
            attron(COLOR_PAIR(GREEN)); // 색상 적용
            printWord(input[i],round,i);
            attroff(COLOR_PAIR(GREEN)); // 원상복귀
        }
        else if(check[i]==YELLOW){
            attron(COLOR_PAIR(YELLOW)); // 색상 적용
            printWord(input[i],round,i);
            attroff(COLOR_PAIR(YELLOW)); // 원상복귀
        }
        else if(check[i]==RED){
            attron(COLOR_PAIR(RED)); // 색상 적용
            printWord(input[i],round,i);
            attroff(COLOR_PAIR(RED)); // 원상복귀
        }
        else{
            printWord(input[i],round,i);
        }
        if(check[i]!=BLACK)
            usleep(500000);
    }
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
