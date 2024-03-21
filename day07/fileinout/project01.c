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

	printf("생성할 아이디를 입력하세요 : \n");
	scanf("%s", ID);

	printf("생성할 비밀번호를 입력하세요 : \n");
	scanf("%s", PASSWORD);

	printf("입력된 ID와 PASSWORD는 %s, %s 입니다. \n", ID, PASSWORD);


	printf("------------------------------------------------------\n");
	printf("본인의 정보가 저장된 파일을 오픈할려면 ID와 PASSWORD를 입력해 주세요");

	printf("아이디를 입력하세요 : \n");
	scanf("%s", EnterID);

	printf("비밀번호를 입력하세요 : \n");
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
		printf("등록된 ID 혹은 PASSWORD가 틀렸습니다.");
	}
}


void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}