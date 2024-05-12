#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncursesw/curses.h>
#include <unistd.h>
#include "drawlib.h"
#include "errlib.h"

char getWord(Word c);
//이거 함수 두개 합칠 수 있을듯여?
// chckRightWord()에 checkColor() 구현함
//Color checkColor(Word input[], Word answer[]);
int checkCorrect(Color after[]);
int checkRightWord(Word input[], Word answer[], Color after[]);
void initColor(Color after[]);

int onGame(Word answer[6]){
    printMainBackground();

    Color after[6] = {RED,RED,RED,RED,RED,RED};
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
                    if(checkRightWord(w,answer,after)){
                        changeColor(after,w,round);
                        if(checkCorrect(after)){
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

int checkRightWord(Word input[], Word answer[], Color after[]){   //check if the word exists
    initColor(after);
    FILE *fp = fopen("filtered_data.csv", "r");
    if (!fp) {
        printf("Failed to open the file(chk)\n");
        return 1;
    }

    char buffer[1024];
    int col_idx = 2;  // column in which splitted string(alphabet) is stored
    int cur_idx = 0;

    // compare input with anwer(alphabet version) in column 3
    while (fgets(buffer, 1024, fp)) {
        // Trim newline character if present
        buffer[strcspn(buffer, "\n")] = 0;
        cur_idx = 0;
        char *token = strtok(buffer, ",");
        while (token) {
            if (cur_idx == col_idx) {
                if(cmp(input, token)){  // if input is in the file
                    // compare and set color array "after"
                    for(int i=0;i<6;i++){
                        printw("%c",getWord(answer[i]));
                    }

                    for(int i=0;i<6;i++){
                        for(int j=0;j<6;j++){
                            if(getWord(input[i]) == getWord(answer[j])){
                                if(i==j){
                                    after[i] = GREEN;
                                    break;
                                }
                                else{
                                    after[i] = YELLOW;
                                }
                                
                            }
                            
                        }
                    }
                    fclose(fp);
                    return 1;
                }
                
            }
            token = strtok(NULL, ",");
            cur_idx++;
        }
    }

    fclose(fp);
    return 0;
}

int checkCorrect(Color after[]){  //check if the word is correct
    // if all green, return 1 (correct)
    for(int i=0;i<6;i++){
        if(after[i] != GREEN){
            return 0;
        }
    }
    //printf("correct!\n");
    return 1;
    
}

int cmp(Word input[], char *token){
    for(int i=0;i<6;i++){
        if(getWord(input[i]) != token[i]){
            return 0;
        }
    }
    return 1;
}

void initColor(Color after[]){
    for(int i=0;i<6;i++){
        after[i] = RED;
    }

}

char getWord(Word c){
    
    switch(c){
        case R: return 'R';
        case S: return 'S';
        case E: return 'E';
        case F: return 'F';
        case A: return 'A';
        case Q: return 'Q';
        case T: return 'T';
        case D: return 'D';
        case W: return 'W';
        case C: return 'C';
        case Z: return 'Z';
        case X: return 'X';
        case V: return 'V';
        case G: return 'G';
        case K: return 'K';
        case I: return 'I';
        case J: return 'J';
        case U: return 'U';
        case H: return 'H';
        case Y: return 'Y';
        case N: return 'N';
        case B: return 'B';
        case M: return 'M';
        case L: return 'L';
        default: return 0;
    }
    
}