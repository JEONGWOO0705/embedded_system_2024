#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#define BUF_SIZE 100
void error_handling(char* message);

void main() {

	int fd;
	char msg[BUF_SIZE];
	char BUF[BUF_SIZE];
	char ID[BUF_SIZE];
	char PASSWORD[BUF_SIZE];
	char AddreddBook[BUF_SIZE];
	char EnterID[BUF_SIZE];
	char EnterPASSWORD[BUF_SIZE];

	printf("������ ���̵� �Է��ϼ��� : \n");
	scanf("%s", ID);

	printf("������ ��й�ȣ�� �Է��ϼ��� : \n");
	scanf("%s", PASSWORD);

	printf("�Էµ� ID�� PASSWORD�� %s, %s �Դϴ�. \n", ID, PASSWORD);


	printf("------------------------------------------------------\n");
	printf("������ ������ ����� ������ �����ҷ��� ID�� PASSWORD�� �Է��� �ּ���");

	printf("���̵� �Է��ϼ��� : \n");
	scanf("%s", EnterID);

	printf("��й�ȣ�� �Է��ϼ��� : \n");
	scanf("%s", EnterPASSWORD);

	if (strcmp(EnterID, ID) == 0 && strcmp(EnterPASSWORD, PASSWORD) == 0) {
		fd = open("HWANG.txt", O_RDONLY);
		if (fd == -1)
			error_handling("open()error\n");
		printf("file descriptor: %d \n", fd);

		if (read(fd, BUF, sizeof(BUF)) == -1)
			error_handling("read() error\n");
		printf("file data: %s \n", BUF);
		close(fd);
	
	}
	else {
		printf("��ϵ� ID Ȥ�� PASSWORD�� Ʋ�Ƚ��ϴ�.");
	}
}


void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}