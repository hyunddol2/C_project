/*���������� ����(���� �Է�)(2022.01.27)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

	char name[100];
	char playerRsp[9], comRsp[9];
	int comNumRsp = 5, playerNumRsp = 5;
	int comWin = 0, playerWin = 0, draw = 0;

	printf("�̸�: ");	//���� �λ� �� ���� �ȳ� �޽���
	gets(name);
	printf("\n�ȳ��ϼ��� %s��!\n\n", name);
	printf("< ���� �� �ȳ� >\n");
	printf("rock, scissors, paper, end �� �ϳ��� �Է����ּ���\n");
	printf("���� 3�� �̱�� ����� ���� �¸�!\n\n");
	printf("< ���������� ���� ���� >\n");

	while (!(comWin==3 || playerWin==3)) {

		while (1) {		//player ����������
			printf("%s: ", name);
			gets(playerRsp);
			if (!(strcmp(playerRsp, "rock") && strcmp(playerRsp, "scissors") && strcmp(playerRsp, "paper") && strcmp(playerRsp, "end")))
				break;
			printf("�߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���.\n\n");
		}


		if (!(strcmp(playerRsp, "end"))) break;	//���� ����

		if (!strcmp(playerRsp, "rock"))
			playerNumRsp = 1;
		else if (!strcmp(playerRsp, "scissors"))
			playerNumRsp = 2;
		else if (!strcmp(playerRsp, "paper"))
			playerNumRsp = 3;


		srand((unsigned)time(NULL));	//��ǻ�� ����������
		comNumRsp = rand() % 3 + 1;

		if (comNumRsp == 1)
			strcpy(comRsp, "rock");
		else if (comNumRsp == 2)
			strcpy(comRsp, "scissors");
		if (comNumRsp == 3)
			strcpy(comRsp, "paper");

		printf("com: %s\n", comRsp);


		printf("\n���: ");	// ���������� ���
		if ((playerNumRsp == 1 && comNumRsp == 2) || (playerNumRsp == 2 && comNumRsp == 3) || (playerNumRsp == 3 && comNumRsp == 1)) {
			playerWin++;
			printf("%s ��!\n", name);
		}
		else if ((comNumRsp == 1 && playerNumRsp == 2) || (comNumRsp == 2 && playerNumRsp == 3) || (comNumRsp == 3 && playerNumRsp == 1)) {
			comWin++;
			printf("com ��!\n");
		}
		else {
			draw++;
			printf("���º�!\n");
		}
		
		printf("%s: %d��  |  com: %d��  |  ���º�: %d\n", name, playerWin, comWin, draw);
		printf("------------------------------------------\n\n");
	};

	printf("*********************\n");
	if (playerWin == 3)
		printf("���� �¸�: %s\n", name);
	else if (comWin == 3)
		printf("���� �¸�: com\n");
	printf("���������� ���� ����\n");
	printf("*********************\n");

	return 0;
}



// �߰��� �� �ִ� ���: 1) 1, 2, 3 ��� ����, ����, ���� �Է� 2) ���й� Ƚ�� ī���� 3) srand(time)�� �Ѱ�- �� ������ �ٲ�� ���� �Է��ϸ� ������ �ŵ� �� ����. 4) ����� �Է� ī��Ʈ �ٿ�