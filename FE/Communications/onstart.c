
#include "drawlib.h"

/*
 // 각 자모를 화면 중앙에 맞춰 출력
 int col = (100 - (13 * 5)) / 2; // 5글자와 각 글자 사이의 간격 고려
 int row = (55 - 7) / 2;       // 7은 각 자모가 차지하는 최대 높이
 */

void printGgodle(int row, int col){
    move(row+1,col+1);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,LeftHalf);
    move(row+2,col+1);
    printw("      %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+3,col+1);
    printw("      %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+4,col+1);
    printw("      %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+6,col+3);
    printw("       %s%s%s    ",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+7,col+3);
    printw("       %s%s%s        ",RightHalf,Full,LeftHalf);
    move(row+8,col-1);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);



    move(row+1,col+21);
    printw("      %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
    move(row+2,col+21);
    printw("      %s%s%s",Full,Full,Full);
    move(row+3,col+21);
    printw("      %s%s%s",Full,Full,Full);
    move(row+4,col+21);
    printw("      %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);

    move(row+6, col+21);
    printw("    %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
    move(row+8, col+21);
    printw("      %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
    move(row+9, col+21);
    printw("                   %s%s%s",Full,Full,Full);
    move(row+10, col+21);
    printw("      %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
    move(row+11, col+21);
    printw("      %s%s%s",Full,Full,Full);
    move(row+12, col+21);
    printw("      %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
}

void printStart(int row, int col){
// // 첫 번째 줄: ㅅ ㅣ ㅈ ㅏ ㄱ


    printWord(T,row,col); // ㅅ
    printWord(L,row,col+7); // ㅣ
    printWord(W,row,col+17); // ㅈ
    printWord(K,row,col+29); // ㅏ
    printWord(R,row,col+34); // ㄱ
}

void printHelp(int row, int col){

    printWord(E,row, col+1);     // ㄷ
    printWord(H,row, col+12); // ㅗ
    printWord(D,row, col + 24); // ㅇ
    printWord(N,row, col + 36); // ㅜ
    printWord(A,row, col+48); // ㅁ

}


int onStart(){
    clear();
    char c;
    int height, width;

    printGgodle(1,25);

    int row=18;
    int col=16;
    col+=7;

    move(row,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2513");
    move(row+1,col); printw("%s", u8"\u2503"); move(row+1,col+47); printw("%s", u8"\u2503");
    move(row+2,col); printw("%s", u8"\u2503"); move(row+2,col+47); printw("%s", u8"\u2503");
    move(row+3,col); printw("%s", u8"\u2503"); move(row+3,col+47); printw("%s", u8"\u2503");
    move(row+4,col); printw("%s", u8"\u2503"); move(row+4,col+47); printw("%s", u8"\u2503");
    move(row+5,col); printw("%s", u8"\u2503"); move(row+5,col+47); printw("%s", u8"\u2503");
	
    printStart(row, col);

    move(row+6,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u251B");
    

    row+=16;
    col-=7;

    move(row,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2513");
    
    move(row+1,col); printw("%s", u8"\u2503"); move(row+1,col+62); printw("%s", u8"\u2503");
    move(row+2,col); printw("%s", u8"\u2503"); move(row+2,col+62); printw("%s", u8"\u2503");
    move(row+3,col); printw("%s", u8"\u2503"); move(row+3,col+62); printw("%s", u8"\u2503");
    move(row+4,col); printw("%s", u8"\u2503"); move(row+4,col+62); printw("%s", u8"\u2503");
    move(row+5,col); printw("%s", u8"\u2503"); move(row+5,col+62); printw("%s", u8"\u2503");
	
    
    printHelp(row, col);

      move(row+6,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u251B");
    refresh();

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
            onHelp();
        }
        else if(c == 'S' || c == 's'){
            return 1;
            onStart();
        }
        else{
            printError("          Usage : Q,S,H");
        }
    }
    
    
    
}

