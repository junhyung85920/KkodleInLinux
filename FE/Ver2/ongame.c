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

int onGame(Word answer[6]){
    printMainBackground();

    Color after[6] = {RED,RED,GREEN,RED,YELLOW,RED};

    for(int i=0;i<6;i++){
        Word w[6];
        int count=0;
        while(count<=6){
            char c = getch();
            if((c=='\n'||c=='\r'||c==KEY_ENTER)){
                if(count==6){
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
                    deleteWord(i,--count);
                }
            }
            else if(w[count] = inputWord(c)){
                if(count==6){
                    printError("더 이상 입력할 수 없습니다.");
                }
                else{
                    printWord(w[count],i,count++);
                }
            }
            else{
                printWordError();
            }
        }
        //if(checkCorrect(w,answer))
        if(1){
            changeColor(after,w,i);
            //changeColor(checkColor(w,answer),w,i);
            return i+1;
        } 
    }

    return 0;

}
