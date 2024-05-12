#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <ncursesw/curses.h>
#include <unistd.h>
#include "drawlib.h"
#include "errlib.h"

//이거 함수 두개 합칠 수 있을듯여?
Color checkColor(Word input[], Word answer[]);
int checkCorrect(Word input[], Word answer[]);
int checkRightWord(Word input[]);

int onGame(Word answer[6]){
    printMainBackground();

    Color after[6] = {RED,RED,GREEN,RED,YELLOW,RED};
    int round = 0;
    int count = 0;
    char c;
    Word w[6];

    while(round<6){
        count=0;
        while(count<=6){
            c = getch();
            flushinp();
            if((c=='\n'||c=='\r'||c==KEY_ENTER)){
                if(count==6){
                    if(checkRightWord(w)){
                        changeColor(after,w,round);
                        if(checkCorrect(w,answer)){
                            return round+1;
                        }
                            
                    }
                    else{
                        printError("존재하지 않는 단어 입니다.");
                        deleteRound(round--);
                    }
                    
                    break;
                }
                else{
                    printError("단어를 모두 입력해주세요.");
                }
            }
            else if(c==7 || c==KEY_BACKSPACE){
                if(count==0){
                    printError("지울 수 있는 단어가 없습니다.");
                }
                else{
                    deleteWord(round,--count);
                }
            }
            else if(isWord(c)){
                if(count==6){
                    printError("더 이상 입력할 수 없습니다.");
                }
                else{
                    w[count] = inputWord(c);
                    printWord(w[count],round,count++);
                }
            }
            else{
                printWordError();
            }
        }
        round++;
    }
    printError("횟수끝");;
    return 0;
}

int checkRightWord(Word input[]){
    if(input[0]==R){
        return 1;
    }
    else{
        return 0;
    }
}

int checkCorrect(Word input[], Word answer[]){
    if(input[5]==R){
        return 1;
    }
    else{
        return 0;
    }
    
}