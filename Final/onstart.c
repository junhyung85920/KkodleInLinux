
#include "drawlib.h"

/*
 // 각 자모를 화면 중앙에 맞춰 출력
 int col = (100 - (13 * 5)) / 2; // 5글자와 각 글자 사이의 간격 고려
 int row = (55 - 7) / 2;       // 7은 각 자모가 차지하는 최대 높이
 */

void printGgodle(int row, int col){
    move(row+2,col);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,LeftHalf);
    move(row+3,col);
    printw("      %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+4,col);
    printw("      %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+5,col);
    printw("      %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+7,col+1);
    printw("       %s%s%s    ",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+8,col+1);
    printw("       %s%s%s        ",RightHalf,Full,LeftHalf);
    move(row+9,col-1);
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
    move(row,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2513");

    printWord(T,row, col);     // ㅅ
    printWord(L,row, col+10); // ㅣ
    printWord(W,row, col+21); // ㅈ
    printWord(K,row, col+34); // ㅏ
    printWord(R,row, col+44); // ㄱ

    move(row+1,col); printw("%s", u8"\u2503"); move(row+1,col+56); printw("%s", u8"\u2503");
    move(row+2,col); printw("%s", u8"\u2503"); move(row+2,col+56); printw("%s", u8"\u2503");
    move(row+3,col); printw("%s", u8"\u2503"); move(row+3,col+56); printw("%s", u8"\u2503");
    move(row+4,col); printw("%s", u8"\u2503"); move(row+4,col+56); printw("%s", u8"\u2503");
    move(row+5,col); printw("%s", u8"\u2503"); move(row+5,col+56); printw("%s", u8"\u2503");

    move(row+6,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u251B");
}

void printHelp(int row, int col){

    move(row,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2513");

    printWord(E,row, col);     // ㄷ
    printWord(H,row, col+11); // ㅗ
    printWord(D,row, col+22); // ㅇ
    printWord(N,row, col+33); // ㅜ
    printWord(A,row, col+44); // ㅁ

    move(row+1,col); printw("%s", u8"\u2503"); move(row+1,col+56); printw("%s", u8"\u2503");
    move(row+2,col); printw("%s", u8"\u2503"); move(row+2,col+56); printw("%s", u8"\u2503");
    move(row+3,col); printw("%s", u8"\u2503"); move(row+3,col+56); printw("%s", u8"\u2503");
    move(row+4,col); printw("%s", u8"\u2503"); move(row+4,col+56); printw("%s", u8"\u2503");
    move(row+5,col); printw("%s", u8"\u2503"); move(row+5,col+56); printw("%s", u8"\u2503");

    move(row+6,col);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
    u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501"
    , u8"\u2501", u8"\u2501", u8"\u251B");
}


int onStart(){
    clear();
    char c;
    int height, width;

    printGgodle(1,25);

    int row=24;
    int col=17;
	
    printStart(row, col);
    

    row+=12;
    
    printHelp(row, col);


    
    refresh();

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
            printError("        Usage : Q,S,H");
        }
    }

}

