#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncursesw/curses.h>
#include <unistd.h>
//#include "gamelib.h"
#include "errlib.h"
#include "drawlib.h"

//usage : gcc -o main -w main.c draw.c ongame.c err.c onstart.c onhelp.c -lncursesw
//zip : zip pro.zip *
//transfer : multipass transfer pobi:/home/ubuntu/ELEC462/pro/pro.zip /Users/pobi/Downloads/pro.zip


void init();
Word* createAnswer();

int main() {
    init();
    int m = 1;
    int result = 0;

    //Word answer[6] = {E, K, F, L, A, L};
    Word* answer = createAnswer();
    

    while(1){
        m = onStart();
        if(m == -1){    //quit
            break;
        }
        else if(m == 0){    //help
            onHelp();
        }
        else{   //game
            result = onGame(answer);
            if(result){
                move(48,30);
                printw("%d",result);
                refresh();
                sleep(3);
                break;
                //onSuccess(result);
            }
            else{
                printError("fail");
                break;
                //onFail(answer);
            }
        }
    }
    
    clear();
    endwin(); // curses 모드 종료


    return 0;
}

void init(){
    printf("\e[8;55;90t"); //창크기를 100*55로 설정

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


Word* createAnswer(){
    int file_size = 57015;  // 1 ~ 57015: 57015개
    int idx = 1;    // current row index
    int answer_idx; // answer row index
    int cur_idx = 0;    // current column index
    int col_idx = 2;  // column in which splitted string is stored
    Word* answer = (Word*)malloc(sizeof(Word)*6);
    FILE *fp;

    srand(time(NULL));
    answer_idx = (int)rand()%file_size + 1;
    printf("answer_idx: %d\n", answer_idx);

    fp = fopen("filtered_data.csv", "r");
    if (!fp) {
        printf("Failed to open the file(ans)\n");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, 1024, fp) && idx <= answer_idx) {
        // Trim newline character if present
        buffer[strcspn(buffer, "\n")] = 0;
        cur_idx = 0;
        if(idx == answer_idx){
            char *token = strtok(buffer, ",");
            while (token) {
                if (cur_idx == col_idx) {
                    for(int i=0;i<6;i++){
                        answer[i] = inputWord(token[i]);
                    }
                    break;
                }
                token = strtok(NULL, ",");
                cur_idx++;
            }
            break;
        }
        idx++;
    }

    fclose(fp);

    return answer;
}

