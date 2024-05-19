
#include "drawlib.h"


//ㄱ
void printR(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    refresh();
}

//ㄴ
void printS(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}

//ㄷ
void printE(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}

//ㄹ
void printF(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    
    refresh();
}

//ㅁ
void printA(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,Full,Full,LeftHalf);
    
    refresh();
}

//ㅂ
void printQ(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Quadrantllr,LowerHalf,LowerHalf,LowerHalf,LowerHalf
    ,LowerHalf,Quadrantrlr,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Quadrantlrl,UpperHalf,UpperHalf,UpperHalf,UpperHalf
    ,UpperHalf,Quadrantlrr,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    
    refresh();
}

//ㅅ
void printT(int row, int col){
    move(row+1, col+1);
    printw("    %s%s%s",Quadrantlr,Full,Quadrantll);
    move(row+2, col+1);
    printw("   %s%s%s%s%s",Quadrantlr,Full,UpperHalf,Full,Quadrantll);
    move(row+3, col+1);
    printw("  %s%s%s %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    move(row+4, col+1);
    printw(" %s%s%s   %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll );
    move(row+5, col+1);
    printw("%s%s%s     %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    refresh();
}

//ㅇ
void printD(int row, int col){
    move(row+1, col+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantlr,Quadrantrlr,Full,Full,Full,Full,Full,Quadrantllr,Quadrantll);
    move(row+2, col+1);
    printw("%s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantlrl,Quadrantul,Quadrantur,Quadrantlrr,Full,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantllr,Quadrantll,Quadrantlr,Quadrantrlr,Full,Full,LeftHalf);
    move(row+5, col+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantur,Quadrantlrr,Full,Full,Full,Full,Full,Quadrantlrl,Quadrantul);

    refresh();
}

//ㅈ
void printW(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantlr,LowerHalf,LowerHalf
    ,LowerHalf,LowerHalf,LowerHalf,LowerHalf,LowerHalf
    ,LowerHalf,LowerHalf,Quadrantll);
    move(row+2, col+1);
    printw("   %s%s%s%s%s",Quadrantlr,Full,UpperHalf,Full,Quadrantll);
    move(row+3, col+1);
    printw("  %s%s%s %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    move(row+4, col+1);
    printw(" %s%s%s   %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll );
    move(row+5, col+1);
    printw("%s%s%s     %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    
    refresh();
}

//ㅊ
void printC(int row, int col){
    move(row+1, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantur,UpperHalf
    ,UpperHalf,Quadrantlrr,Full,UpperHalf,Full,Quadrantlrl
    ,UpperHalf,UpperHalf,Quadrantul);
    move(row+3, col+1);
    printw("  %s%s%s %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    move(row+4, col+1);
    printw(" %s%s%s   %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll );
    move(row+5, col+1);
    printw("%s%s%s     %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    refresh();
}

//ㅋ
void printZ(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantlr,LowerHalf,LowerHalf,LowerHalf,LowerHalf,LowerHalf,LowerHalf
    ,LowerHalf,Quadrantrlr,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantur,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf
    ,UpperHalf,Quadrantlrr,Full,LeftHalf);
    move(row+5, col+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    refresh();
}

//ㅌ
void printX(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}

//ㅍ
void printV(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+2, col+1);
    printw("  %s%s   %s%s",Full,Full,Full,Full);
    move(row+3, col+1);
    printw("  %s%s   %s%s",Full,Full,Full,Full);
    move(row+4, col+1);
    printw("  %s%s   %s%s",Full,Full,Full,Full);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);

    refresh();
}

//ㅎ
void printG(int row, int col){
    move(row+1, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantlr,LowerHalf
    ,LowerHalf,LowerHalf,Full,Full,Full,LowerHalf
    ,LowerHalf,LowerHalf,Quadrantll);
    move(row+2, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantur,UpperHalf,UpperHalf
    ,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf
    ,UpperHalf,Quadrantul);
    move(row+3, col+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantlr,Quadrantrlr,Full,Full,Full,Full,Full,Quadrantllr,Quadrantll);
    move(row+4, col+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,Full,Full,Full,LeftHalf);
    move(row+5, col+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantur,Quadrantlrr,Full,Full,Full,Full,Full,Quadrantlrl,Quadrantul);
    
    refresh();
}

//ㅏ
void printK(int row, int col){

    move(row+1, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+2, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,LeftHalf);
    move(row+4, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    refresh();

}
//ㅓ
void printJ(int row, int col){

    move(row+1, col+3);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    move(row+2, col+3);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+3);
    printw("%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(row+4, col+3);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+3);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    refresh();
}
//ㅗ
void printH(int row, int col){
    move(row+1, col+1);
    printw("",RightHalf,Full,LeftHalf);
    move(row+2, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}
//ㅜ
void printN(int row, int col){
    move(row+2, col+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    printw("",RightHalf,Full,LeftHalf);
    move(row+3, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+4, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+5, col+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(row+6, col+1);
    refresh();
}
//ㅡ
void printM(int x, int y){
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}
//ㅣ
void printL(int x, int y){

    move(x+1,y+5);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+2,y+5);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+5);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+4,y+5);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+5,y+5);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    refresh();

}

//ㅑ
void printI(int x, int y){

    move(x+1,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    refresh();

}

//ㅕ
void printU(int x, int y){

    move(x+1,y+2);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    move(x+2,y+2);
    printw("%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,LeftHalf);
    move(x+3,y+2);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    move(x+4,y+2);
    printw("%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,LeftHalf);
    move(x+5,y+2);
    printw("      %s%s%s",RightHalf,Full,LeftHalf);
    refresh();

}

//ㅛ
void printY(int x, int y){

    move(x+2,y+1);
    printw("  %s%s%s %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("  %s%s%s %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("  %s%s%s %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}
//ㅠ
void printB(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
   
    move(x+2,y+1);
    printw("  %s%s%s %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("  %s%s%s %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("  %s%s%s %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    refresh();
}


void printMainBackground(){
    clear();
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            move(2+i*7,6+13*j);
            printw("%s%s%s%s%s%s%s%s%s%s%s%s%s", u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501" , 
            u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", 
            u8"\u2501", u8"\u2501", u8"\u2513"); // 특정 단어 출력
            
            for(int k=1;k<=5;k++){
                move(2+i*7+k,6+13*j);
                printw("%s           %s", u8"\u2503", u8"\u2503"); // 특정 단어 출력
            }
            move(2+i*7+6,6+13*j);
            printw("%s%s%s%s%s%s%s%s%s%s%s%s%s", u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501" , 
            u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", 
            u8"\u2501", u8"\u2501", u8"\u251B"); // 특정 단어 출력
        }
    }
    refresh();
}

void deleteWord(int round,int index){
    for(int i=1;i<=5;i++){
        move(2+round*7+i,6+13*index+1);
        printw("           ");
    }
    refresh();
}


void printWord(Word w, int row, int col){
    switch (w)
    {
        case R: printR(row, col); break;    //ㄱ
        case S: printS(row, col); break;    //ㄴ
        case E: printE(row, col); break;    //ㄷ
        case F: printF(row, col); break;    //ㄹ
        case A: printA(row, col); break;    //ㅁ
        case Q: printQ(row, col); break;    //ㅂ
        case T: printT(row, col); break;    //ㅛ
        case D: printD(row, col); break;    //ㅇ
        case W: printW(row, col); break;    //ㅈ
        case C: printC(row, col); break;    //ㅊ
        case Z: printZ(row, col); break;   //ㅋ
        case X: printX(row, col); break;   //ㅌ
        case V: printV(row, col); break;   //ㅍ
        case G: printG(row, col); break;   //ㅎ
        case K: printK(row, col); break;   //ㅏ
        case J: printJ(row, col); break;   //ㅓ
        case H: printH(row, col); break;   //ㅗ
        case N: printN(row, col); break;   //ㅜ
        case M: printM(row, col); break;   //ㅡ
        case L: printL(row, col); break;   //ㅣ
        case I: printI(row, col); break;   //ㅑ
        case U: printU(row, col); break;   //ㅕ
        case Y: printY(row, col); break;   //ㅛ
        case B: printB(row, col); break;   //ㅠ
        default: break;
    }
}

void changeColor(Color check[], Word input[], int round){
    for(int i=0;i<6;i++){
        if(check[i]==GREEN){
            attron(COLOR_PAIR(GREEN)); // 색상 적용
            printWord(input[i],2+round*7,6+13*i);
            attroff(COLOR_PAIR(GREEN)); // 원상복귀
        }
        else if(check[i]==YELLOW){
            attron(COLOR_PAIR(YELLOW)); // 색상 적용
            printWord(input[i],2+round*7,6+13*i);
            attroff(COLOR_PAIR(YELLOW)); // 원상복귀
        }
        else if(check[i]==RED){
            attron(COLOR_PAIR(RED)); // 색상 적용
            printWord(input[i],2+round*7,6+13*i);
            attroff(COLOR_PAIR(RED)); // 원상복귀
        }
        
        usleep(500000);
    }
    flushinp();
}

void deleteRound(int round){
    for(int i=0;i<6;i++){
        deleteWord(round,i);
    }
}
