
#include "drawlib.h"

void printGgodle(int row, int col){
    printWord(R,col, row + 52); // ㄱ
    printWord(R,col, row + 52); // ㄱ
    printWord(H,col, row + 13); // ㅗ
    printWord(E,col, row + 26); // ㄷ
    printWord(M,col, row + 39); // ㅡ
    printWord(F,col, row + 52); // ㄹ
}

void printStart(int row, int col){
// // 첫 번째 줄: ㅅ ㅣ ㅈ ㅏ ㄱ
    printWord(T,col, row);     // ㅅ
    printWord(L,col, row + 13); // ㅣ
    printWord(W,col, row + 26); // ㅈ
    printWord(K,col, row + 39); // ㅏ
    printWord(R,col, row + 52); // ㄱ
}

void printHelp(int row, int col){
    printWord(E,col + 7, row);     // ㄷ
    printWord(H,col + 7, row + 13); // ㅗ
    printWord(D,col + 7, row + 26); // ㅇ
    printWord(N,col + 7, row + 39); // ㅜ
    printWord(A,col + 7, row + 52); // ㅁ

}


int onStart(){
    clear();
    char c;
    int height, width;


    // 각 자모를 화면 중앙에 맞춰 출력
    int col = (100 - (13 * 5)) / 2; // 5글자와 각 글자 사이의 간격 고려
    int row = (55 - 7) / 2;       // 7은 각 자모가 차지하는 최대 높이

	printStart(row, col);
	printHelp(row, col);

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

