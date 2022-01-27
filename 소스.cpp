/*가위바위보 게임(문자 입력)(2022.01.27)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

	char name[100];
	char playerRsp[9], comRsp[9];
	int comNumRsp = 5, playerNumRsp = 5;
	int comWin = 0, playerWin = 0, draw = 0;

	printf("이름: ");	//시작 인사 및 게임 안내 메시지
	gets(name);
	printf("\n안녕하세요 %s님!\n\n", name);
	printf("< 게임 룰 안내 >\n");
	printf("rock, scissors, paper, end 중 하나를 입력해주세요\n");
	printf("먼저 3번 이기는 사람이 최종 승리!\n\n");
	printf("< 가위바위보 게임 시작 >\n");

	while (!(comWin==3 || playerWin==3)) {

		while (1) {		//player 가위바위보
			printf("%s: ", name);
			gets(playerRsp);
			if (!(strcmp(playerRsp, "rock") && strcmp(playerRsp, "scissors") && strcmp(playerRsp, "paper") && strcmp(playerRsp, "end")))
				break;
			printf("잘못 입력했습니다. 다시 입력해주세요.\n\n");
		}


		if (!(strcmp(playerRsp, "end"))) break;	//게임 종료

		if (!strcmp(playerRsp, "rock"))
			playerNumRsp = 1;
		else if (!strcmp(playerRsp, "scissors"))
			playerNumRsp = 2;
		else if (!strcmp(playerRsp, "paper"))
			playerNumRsp = 3;


		srand((unsigned)time(NULL));	//컴퓨터 가위바위보
		comNumRsp = rand() % 3 + 1;

		if (comNumRsp == 1)
			strcpy(comRsp, "rock");
		else if (comNumRsp == 2)
			strcpy(comRsp, "scissors");
		if (comNumRsp == 3)
			strcpy(comRsp, "paper");

		printf("com: %s\n", comRsp);


		printf("\n결과: ");	// 가위바위보 결과
		if ((playerNumRsp == 1 && comNumRsp == 2) || (playerNumRsp == 2 && comNumRsp == 3) || (playerNumRsp == 3 && comNumRsp == 1)) {
			playerWin++;
			printf("%s 승!\n", name);
		}
		else if ((comNumRsp == 1 && playerNumRsp == 2) || (comNumRsp == 2 && playerNumRsp == 3) || (comNumRsp == 3 && playerNumRsp == 1)) {
			comWin++;
			printf("com 승!\n");
		}
		else {
			draw++;
			printf("무승부!\n");
		}
		
		printf("%s: %d승  |  com: %d승  |  무승부: %d\n", name, playerWin, comWin, draw);
		printf("------------------------------------------\n\n");
	};

	printf("*********************\n");
	if (playerWin == 3)
		printf("최종 승리: %s\n", name);
	else if (comWin == 3)
		printf("최종 승리: com\n");
	printf("가위바위보 게임 종료\n");
	printf("*********************\n");

	return 0;
}



// 추가할 수 있는 요소: 1) 1, 2, 3 대신 가위, 바위, 보로 입력 2) 승패무 횟수 카운팅 3) srand(time)의 한계- 초 단위가 바뀌기 전에 입력하면 연승을 거둘 수 있음. 4) 사용자 입력 카운트 다운