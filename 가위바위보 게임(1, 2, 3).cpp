/*���������� ����(1, 2, 3)(2022.01.11)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	char name[100];
	int comRsp, playerRsp=5;

	printf("�̸�: ");	//���� �λ� �� ���� �ȳ� �޽���
	gets(name);
	printf("\n�ȳ��ϼ��� %s��!\n\n", name);
	printf("< ���� �� �ȳ� >\n");
	printf("����(1), ����(2), ��(3), ����(0) �� �ϳ��� �Է����ּ���\n\n");
	printf("< ���������� ���� ���� >\n");

	while (1) {
		
		while (1) {		//player ����������
			printf("%s: ", name);
			scanf("%d", &playerRsp);
			if (playerRsp == 0 || playerRsp == 1 || playerRsp == 2 || playerRsp == 3)
				break;
			printf("�߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���.\n\n");
		}

		if (playerRsp == 0) break;	//���� ����

		srand((unsigned)time(NULL));	//��ǻ�� ����������
		comRsp = rand() % 3 + 1;
		printf("com: %d\n", comRsp);

		printf("���: ");	// ���������� ���
		if ((playerRsp == 2 && comRsp == 1) || (playerRsp == 1 && comRsp == 3) || (playerRsp == 3 && comRsp == 2))
			printf("%s ��!", name);
		else if((comRsp == 2 && playerRsp == 1) || (comRsp == 1 && playerRsp == 3) || (comRsp == 3 && playerRsp == 2))
			printf("com ��!");
		else
			printf("���º�!");
		printf("\n\n");
	};
	printf("���������� ���� ����\n");
	return 0;
};


// �߰��� �� �ִ� ���: 1) 1, 2, 3 ��� ����, ����, ���� �Է� 2) ���й� Ƚ�� ī���� 3) srand(time)�� �Ѱ�- �� ������ �ٲ�� ���� �Է��ϸ� ������ �ŵ� �� ����.