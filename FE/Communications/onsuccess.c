
#include "drawlib.h"

void printSuccess(int row, int col){
    move(row+1, col+1);
    printw("       %s%s%s%s%s         %s%s%s",Quadrantlr,Full,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+2, col+1);
    printw("      %s%s%s%s%s%s%s        %s%s%s",Quadrantlr,Full,Full,UpperHalf,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+3, col+1);
    printw("     %s%s%s%s %s%s%s%s       %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+4, col+1);
    printw("    %s%s%s%s   %s%s%s%s   %s%s%s%s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full, Quadrantll
    ,Full,Full,Full,Full,Full,Full); 
    move(row+5, col+1);
    printw("   %s%s%s%s     %s%s%s%s     %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+6, col+1);
    printw("  %s%s%s%s       %s%s%s%s    %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    move(row+7, col+1);
    printw(" %s%s%s%s         %s%s%s%s   %s%s%s",Quadrantlr,Full,Full,Quadrantul,Quadrantur,Full,Full,Quadrantll,RightHalf,Full,Full);
    
    move(row+9, col+1);
    printw("         %s%s%s%s%s%s%s%s%s",Quadrantlr,Quadrantrlr,Full,Full,Full,Full,Full,Quadrantllr,Quadrantll);
    move(row+10, col+1);
    printw("        %s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantlrl,Quadrantul,Quadrantur,Quadrantlrr,Full,Full,LeftHalf);
    move(row+11, col+1);
    printw("        %s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+12, col+1);
    printw("        %s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantllr,Quadrantll,Quadrantlr,Quadrantrlr,Full,Full,LeftHalf);
    move(row+13, col+1);
    printw("         %s%s%s%s%s%s%s%s%s",Quadrantur,Quadrantlrr,Full,Full,Full,Full,Full,Quadrantlrl,Quadrantul);

    move(row+1,col+28);
    printw("  %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,LeftHalf);
    move(row+2,col+28);
    printw("              %s%s%s",RightHalf,Full,LeftHalf);
    move(row+3,col+28);
    printw("              %s%s%s",RightHalf,Full,LeftHalf);
    move(row+4,col+28);
    printw("              %s%s%s",RightHalf,Full,LeftHalf);
    move(row+5,col+28);
    printw("       %s%s%s    %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+6,col+28);
    printw("       %s%s%s        ",RightHalf,Full,LeftHalf);
    move(row+7,col+28);
    printw(" %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full,Full);
   
    move(row+9,col+28);
    printw("     %s%s%s%s%s%s%s%s%s",Quadrantlr,Quadrantrlr,Full,Full,Full,Full,Full,Quadrantllr,Quadrantll);
    move(row+10,col+28);
    printw("    %s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantlrl,Quadrantul,Quadrantur,Quadrantlrr,Full,Full,LeftHalf);
    move(row+11,col+28);
    printw("    %s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+12, col+28);
    printw("    %s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantllr,Quadrantll,Quadrantlr,Quadrantrlr,Full,Full,LeftHalf);
    move(row+13, col+28);
    printw("     %s%s%s%s%s%s%s%s%s",Quadrantur,Quadrantlrr,Full,Full,Full,Full,Full,Quadrantlrl,Quadrantul);

}



void onSuccess(int score){
    clear();
    printSuccess(10,15);
    move(31,43);
    printw("횟수 : %d", score);
    refresh();
    sleep(3);
}