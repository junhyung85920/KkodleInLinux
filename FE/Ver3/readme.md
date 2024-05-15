
#  기본 정보
- 창 크기 : 55*90
- 박스 크기 : 7*13

# 정의된 변수
- Word : 입력가능한 단어들을 열거형으로 표현한 변수
- Color : 변화될 색깔들을 열거형으로 표현한 변수

# 정의된 함수
 - onGame in ongame.c : 게임 메인 화면
 - onSuccess in onsuccess.c : 성공시 화면
 - onFail in onfail.c : 실패시 화면
 - onSatrt in onstart.c : 시작화면
 - onHelp in onhelp.c : 도움말화면

 # 변경사항
 - 해더파일을 좀더 단순화 함
    - drawlib은 출력되는 모든것을 다루고, gamelib은 출력이 아닌 판단과정에서 다른 곳에서 필요한 것들을 다룸, errlib은 추후 필요한 err를 다룰 예정
    - 그러기 위해서 파일들을 다시 개편함
 - main에서는 gamelib만 include하고, 나머지에서는 그냥 drawlib를 include하면 됨

 # 해야 할 일
 - 김준형
    - ongame.c 에서 정답 임시 출력
    - 색깔 안바뀌는 오류 수정(?) -> 제가 건드린걸 수도...
 - 장현호 
    - 출력 함수에서 prinw("")과 같이 의미 없는 것들 삭제 -> 메모리만 잡아먹음
    - 시작화면 만들기, 성공 화면 만들기
    - 성공화면에 횟수를 출력해야하는데, 이 과정에서 함수를 printOne과 같이 만들고, 이를 통합적으로 다루는 printNumber가 drawlib에 있었으면 좋겠음. 즉 draw.c에는 printOne이 있고, drawlib에는 printNumber만 정의되어 있는 형식
    - printWord에 row,col을 입력하면 문자가 출력될겁니다. onfail.c에서 활용하는거 보고, onstart에 사용해주세요.
 - 조재용
    - 기타 추가사항 변경및 실패 꾸미기(추가사항)