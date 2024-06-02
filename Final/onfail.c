
#include "drawlib.h"

void printFail(int row, int col){
    move(row+1, col+1);
    printw("       %s%s%s%s%s         %s%s%s",Quadrantlr,Full,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+2, col+1);
    printw("      %s%s%s%s%s%s%s        %s%s%s",Quadrantlr,Full,Full,UpperHalf,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+3, col+1);
    printw("     %s%s%s%s %s%s%s%s       %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+4, col+1);
    printw("    %s%s%s%s   %s%s%s%s      %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+5, col+1);
    printw("   %s%s%s%s     %s%s%s%s     %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+6, col+1);
    printw("  %s%s%s%s       %s%s%s%s    %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+7, col+1);
    printw(" %s%s%s%s         %s%s%s%s   %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+9, col+1);
    printw("       %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
    move(row+10, col+1);
    printw("                    %s%s%s",Full,Full,Full);
    move(row+11, col+1);
    printw("       %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
    move(row+12, col+1);
    printw("       %s%s%s",Full,Full,Full);
    move(row+13, col+1);
    printw("       %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);

    move(row+1,col+28);
    printw("                   %s%s%s  %s%s%s",RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+2,col+28);
    printw("                   %s%s%s  %s%s%s",RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+3,col+28);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s  %s%s%s  %s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+4,col+28);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s  %s%s%s  %s%s%s",UpperHalf,UpperHalf,Quadrantlrr,Full,Full,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,Full,Full,Quadrantlrl,UpperHalf,UpperHalf,RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+5,col+28);
    printw("   %s%s%s      %s%s%s    %s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,LeftHalf,RightHalf,Full,Full,LowerHalf,LowerHalf,Quadrantrlr,Full,Full);
    move(row+6,col+28);
    printw("   %s%s%s      %s%s%s    %s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,LeftHalf,RightHalf,Full,Full,Full,Full,Full,Full,Full);
    move(row+7,col+28);
    printw("   %s%s%s      %s%s%s    %s%s%s  %s%s%s",RightHalf,Full,Full,Full,Full,LeftHalf,RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+8,col+28);
    printw("   %s%s%s      %s%s%s    %s%s%s  %s%s%s",RightHalf,Full,Full,Full,Full,LeftHalf,RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+9,col+28);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s  %s%s%s  %s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+10,col+28);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s  %s%s%s  %s%s%s",UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,RightHalf,Full,Full,RightHalf,Full,Full);
    move(row+11,col+28);
     printw("                   %s%s%s  %s%s%s",RightHalf,Full,Full,RightHalf,Full,Full);
}

void printEnswer(Word answer[6]){
    int i;
    for(i=0;i<6;i++){
        printWord(answer[i],32,12+11*i);
    }
}


void onFail(Word answer[6]){
    clear();
    printFail(10,15);
    move(31,43);
    printw("정답은 ");
    printEnswer(answer);
    refresh();
    getch();
}