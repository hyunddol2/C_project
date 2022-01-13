/*가위바위보 게임(1, 2, 3)(2022.01.11)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	char name[100];
	int comRsp, playerRsp=5;

	printf("이름: ");	//시작 인사 및 게임 안내 메시지
	gets(name);
	printf("\n안녕하세요 %s님!\n\n", name);
	printf("< 게임 룰 안내 >\n");
	printf("가위(1), 바위(2), 보(3), 종료(0) 중 하나를 입력해주세요\n\n");
	printf("< 가위바위보 게임 시작 >\n");

	while (1) {
		
		while (1) {		//player 가위바위보
			printf("%s: ", name);
			scanf("%d", &playerRsp);
			if (playerRsp == 0 || playerRsp == 1 || playerRsp == 2 || playerRsp == 3)
				break;
			printf("잘못 입력했습니다. 다시 입력해주세요.\n\n");
		}

		if (playerRsp == 0) break;	//게임 종료

		srand((unsigned)time(NULL));	//컴퓨터 가위바위보
		comRsp = rand() % 3 + 1;
		printf("com: %d\n", comRsp);

		printf("결과: ");	// 가위바위보 결과
		if ((playerRsp == 2 && comRsp == 1) || (playerRsp == 1 && comRsp == 3) || (playerRsp == 3 && comRsp == 2))
			printf("%s 승!", name);
		else if((comRsp == 2 && playerRsp == 1) || (comRsp == 1 && playerRsp == 3) || (comRsp == 3 && playerRsp == 2))
			printf("com 승!");
		else
			printf("무승부!");
		printf("\n\n");
	};
	printf("가위바위보 게임 종료\n");
	return 0;
};


// 추가할 수 있는 요소: 1) 1, 2, 3 대신 가위, 바위, 보로 입력 2) 승패무 횟수 카운팅 3) srand(time)의 한계- 초 단위가 바뀌기 전에 입력하면 연승을 거둘 수 있음.