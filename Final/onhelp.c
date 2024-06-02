
#include "drawlib.h"


void onHelp(){
  clear();
    mvprintw(9, 5, "<게임 도움말>");
  mvprintw(
      11, 5,
      "1. 플레이어는 자음과 모음 도합 6개로 된 한글 단어를 추측하고 추측한 단어에 대한");
  mvprintw(12,8, "피드백을 받습니다. 예) 강물 -> ㄱ ㅏ ㅇ ㅁ ㅜ ㄹ 입력");
  mvprintw(
      14, 5,
      "2. 각 글자가 맞는 위치에 있는지 여부를 나타내는 색상이 표시됩니다");
  
  attron(COLOR_PAIR(GREEN));
  mvprintw(15,6," *초록색");
  attroff(COLOR_PAIR(GREEN));
  mvprintw(15,13," - 해당 글자가 올바른 위치에 있음 ");
  attron(COLOR_PAIR(YELLOW));
  mvprintw(16,6," *노란색");
  attroff(COLOR_PAIR(YELLOW));
  mvprintw(16,13," - 해당 글자가 단어에 포함되지만 위치가 틀렸음");
  attron(COLOR_PAIR(RED));
  mvprintw(17,6," *빨간색");
  attroff(COLOR_PAIR(RED));
  mvprintw(17,13," - 해당 글자가 단어에 없음을 나타냄");
  mvprintw(19, 5,
      "3. 피드백을 받은 후에는 플레이어가 새로운 추측을 할 수 있고,");
  mvprintw(20,8,
     "이는 올바른 단어를 찾을 때까지 6번의 기회가 주어집니다.");
  mvprintw(22,5, "4. 플레이어가 정확한 단어를 추측하면 게임이 종료됩니다.");
  mvprintw(24,5, "5. 멀티 게임");
  mvprintw(25,7, ": 게임 방식은 싱글모드와 동일하지만 게임 진행 전 플레이어 간 정답 교환이 필요합니다.");
  mvprintw(27,8, "- 상대방이 맞추게 할 단어를 사용자 본인이 직접 입력합니다.");
  mvprintw(28,8, "- 그 후 게임이 시작되면 상대방이 낸 문제 단어를 맞추게 됩니다.");
  mvprintw(29,8, "- 모든 플레이어의 게임이 종료되면 본인의 성공 횟수와 더불어");
  mvprintw(30,10, "상대방은 몇 번 만에 맞추었는지 그 횟수가 출력됩니다.");
  
  


  // 화면 갱신
  refresh();
  // 사용자 입력 대기 (키 입력을 기다림)
  getch();
  
  //onStart();


 }
