
#include "drawlib.h"

void onHelp(){
  clear();
    mvprintw(1, 1, "게임 도움말:");
  mvprintw(
      3, 1,
      "1. 플레이어는 자음과 모음 도합 6개로 된 한글 단어를 추측하고 추측한 "
      "단어에 대한 피드백을 받습니다. 예) 강물 -> ㄱ ㅏ ㅇ ㅁ ㅜ ㄹ 입력");
  mvprintw(
      5, 1,
      "2. 각 글자가 맞는 위치에 있는지 여부를 나타내는 색상이 표시됩니다:");
  attron(GREEN);
  printw(" 초록색 ");
  attroff(GREEN);
  printw("- 해당 글자가 올바른 위치에 있음,");
  attron(COLOR_PAIR(2));
  printw(" 노란색 ");
  attroff(COLOR_PAIR(2));
  printw("- 해당 글자가 단어에 포함되지만 위치가 틀렸음,");
  attron(COLOR_PAIR(3));
  printw(" 회색 ");
  attroff(COLOR_PAIR(3));
  printw("- 해당 글자가 단어에 없음을 나타냅니다.");
  mvprintw(7, 1,
           "3. 피드백을 받은 후에는 플레이어가 새로운 추측을 할 수 있고, 이는 "
           "올바른 단어를 찾을 때까지 6번의 기회가 주어집니다.");
  mvprintw(9, 1, "4. 플레이어가 정확한 단어를 추측하면 게임이 종료됩니다.");

  // 화면 갱신
  refresh();
  // 사용자 입력 대기 (키 입력을 기다림)
  getch();
  
  onStart();
}
