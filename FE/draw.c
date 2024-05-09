#include <ncursesw/curses.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include "drawlib.h"


void printBox(int x, int y){
    move(x,y);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s", u8"\u250F", u8"\u2501", u8"\u2501", u8"\u2501" , 
    u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", 
    u8"\u2501", u8"\u2501", u8"\u2513"); // 특정 단어 출력
    
    for(int i=1;i<=5;i++){
        move(x+i,y);
        printw("%s           %s", u8"\u2503", u8"\u2503"); // 특정 단어 출력
    }
    move(x+6,y);
    printw("%s%s%s%s%s%s%s%s%s%s%s%s%s", u8"\u2517", u8"\u2501", u8"\u2501", u8"\u2501" , 
    u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", u8"\u2501", 
    u8"\u2501", u8"\u2501", u8"\u251B"); // 특정 단어 출력
   
    // 화면 업데이트
    refresh();
}

void printMainBackground(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printBox(2+i*7,6+13*j);
        }
    }
}

void cleanBox(int x, int y){
    for(int i=1;i<=5;i++){
        move(x+i,y+1);
        printw("           ");
    }
    refresh();
}

void deleteWord(int round,int index){
    cleanBox(2+round*7,6+13*index);
}

int isWord(char c){
    switch(c){
        case 'r': return 1;
        case 's': return 1;
        case 'e': return 1;
        case 'f': return 1;
        case 'a': return 1;
        case 'q': return 1;
        case 't': return 1;
        case 'd': return 1;
        case 'w': return 1;
        case 'c': return 1;
        case 'z': return 1;
        case 'x': return 1;
        case 'v': return 1;
        case 'g': return 1;
        default: return 0;
    }

}

Word inputWord(char c){
    switch(c){
        case 'r': return R;
        case 's': return S;
        case 'e': return E;
        case 'f': return F;
        case 'a': return A;
        case 'q': return Q;
        case 't': return T;
        case 'd': return D;
        case 'w': return W;
        case 'c': return C;
        case 'z': return Z;
        case 'x': return X;
        case 'v': return V;
        case 'g': return G;
        default: return -1;
    }
}

void printWord(Word w, int round, int index){
    switch (w)
    {
        case R: printR(2+round*7,6+13*index); break;    //ㄱ
        case S: printS(2+round*7,6+13*index); break;    //ㄴ
        case E: printE(2+round*7,6+13*index); break;    //ㄷ
        case F: printF(2+round*7,6+13*index); break;    //ㄹ
        case A: printA(2+round*7,6+13*index); break;    //ㅁ
        case Q: printQ(2+round*7,6+13*index); break;    //ㅂ
        case T: printT(2+round*7,6+13*index); break;    //ㅛ
        case D: printD(2+round*7,6+13*index); break;    //ㅇ
        case W: printW(2+round*7,6+13*index); break;    //ㅈ
        case C: printC(2+round*7,6+13*index); break;    //ㅊ
        case Z: printZ(2+round*7,6+13*index); break;   //ㅋ
        case X: printX(2+round*7,6+13*index); break;   //ㅌ
        case V: printV(2+round*7,6+13*index); break;   //ㅍ
        case G: printG(2+round*7,6+13*index); break;   //ㅎ
        default: break;
    }
}

//ㄱ
void printR(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    refresh();
}

//ㄴ
void printS(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}

//ㄷ
void printE(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}

//ㄹ
void printF(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    
    refresh();
}

//ㅁ
void printA(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full
    ,Full,Full,Full,Full,Full,LeftHalf);
    
    refresh();
}

//ㅂ
void printQ(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Quadrantllr,LowerHalf,LowerHalf,LowerHalf,LowerHalf
    ,LowerHalf,Quadrantrlr,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Quadrantlrl,UpperHalf,UpperHalf,UpperHalf,UpperHalf
    ,UpperHalf,Quadrantlrr,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    
    refresh();
}

//ㅅ
void printT(int x, int y){
    move(x+1,y+1);
    printw("    %s%s%s",Quadrantlr,Full,Quadrantll);
    move(x+2,y+1);
    printw("   %s%s%s%s%s",Quadrantlr,Full,UpperHalf,Full,Quadrantll);
    move(x+3,y+1);
    printw("  %s%s%s %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    move(x+4,y+1);
    printw(" %s%s%s   %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll );
    move(x+5,y+1);
    printw("%s%s%s     %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    refresh();
}

//ㅇ
void printD(int x, int y){
    move(x+1,y+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantlr,Quadrantrlr,Full,Full,Full,Full,Full,Quadrantllr,Quadrantll);
    move(x+2,y+1);
    printw("%s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantlrl,Quadrantul,Quadrantur,Quadrantlrr,Full,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,LeftHalf,RightHalf,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s%s%s %s%s%s%s%s",RightHalf,Full,Full,Quadrantllr,Quadrantll,Quadrantlr,Quadrantrlr,Full,Full,LeftHalf);
    move(x+5,y+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantur,Quadrantlrr,Full,Full,Full,Full,Full,Quadrantlrl,Quadrantul);

    refresh();
}

//ㅈ
void printW(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantlr,LowerHalf,LowerHalf
    ,LowerHalf,LowerHalf,LowerHalf,LowerHalf,LowerHalf
    ,LowerHalf,LowerHalf,Quadrantll);
    move(x+2,y+1);
    printw("   %s%s%s%s%s",Quadrantlr,Full,UpperHalf,Full,Quadrantll);
    move(x+3,y+1);
    printw("  %s%s%s %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    move(x+4,y+1);
    printw(" %s%s%s   %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll );
    move(x+5,y+1);
    printw("%s%s%s     %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    
    refresh();
}

//ㅊ
void printC(int x, int y){
    move(x+1,y+1);
    printw("    %s%s%s",RightHalf,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantur,UpperHalf
    ,UpperHalf,Quadrantlrr,Full,UpperHalf,Full,Quadrantlrl
    ,UpperHalf,UpperHalf,Quadrantul);
    move(x+3,y+1);
    printw("  %s%s%s %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    move(x+4,y+1);
    printw(" %s%s%s   %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll );
    move(x+5,y+1);
    printw("%s%s%s     %s%s%s",Quadrantlr,Full,Quadrantul,Quadrantur,Full,Quadrantll);
    refresh();
}

//ㅋ
void printZ(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantlr,LowerHalf,LowerHalf,LowerHalf,LowerHalf,LowerHalf,LowerHalf
    ,LowerHalf,Quadrantrlr,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantur,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf
    ,UpperHalf,Quadrantlrr,Full,LeftHalf);
    move(x+5,y+1);
    printw("        %s%s%s",RightHalf,Full,LeftHalf);
    refresh();
}

//ㅌ
void printX(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+3,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+4,y+1);
    printw("%s%s%s",RightHalf,Full,LeftHalf);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    refresh();
}

//ㅍ
void printV(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);
    move(x+2,y+1);
    printw("  %s%s   %s%s",Full,Full,Full,Full);
    move(x+3,y+1);
    printw("  %s%s   %s%s",Full,Full,Full,Full);
    move(x+4,y+1);
    printw("  %s%s   %s%s",Full,Full,Full,Full);
    move(x+5,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",RightHalf,Full,Full,Full,Full,Full,Full
    ,Full,Full,Full,LeftHalf);

    refresh();
}

//ㅎ
void printG(int x, int y){
    move(x+1,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantlr,LowerHalf
    ,LowerHalf,LowerHalf,Full,Full,Full,LowerHalf
    ,LowerHalf,LowerHalf,Quadrantll);
    move(x+2,y+1);
    printw("%s%s%s%s%s%s%s%s%s%s%s",Quadrantur,UpperHalf,UpperHalf
    ,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf,UpperHalf
    ,UpperHalf,Quadrantul);
    move(x+3,y+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantlr,Quadrantrlr,Full,Full,Full,Full,Full,Quadrantllr,Quadrantll);
    move(x+4,y+1);
    printw("%s%s%s     %s%s%s",RightHalf,Full,Full,Full,Full,LeftHalf);
    move(x+5,y+1);
    printw(" %s%s%s%s%s%s%s%s%s",Quadrantur,Quadrantlrr,Full,Full,Full,Full,Full,Quadrantlrl,Quadrantul);
    
    refresh();
}