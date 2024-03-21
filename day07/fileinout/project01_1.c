#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#define BUF_SIZE 100
void error_handling(char* message);

void main() {
	int fd;
	int fp;
	int pp
	char msg[BUF_SIZE];
	char BUF[BUF_SIZE];
	char TID[BUF_SIZE];
	char TPASSWORD[BUF_SIZE];
	char AddreddBook[BUF_SIZE];
	char EnterID[BUF_SIZE];
	char EnterPASSWORD[BUF_SIZE];

	fp = open("id.txt", O_RDONLY);
	if (fp == -1)
		error_handling("open()error\n");
	printf("file descriptor: %d \n", fp);

	if (read(fp, TID, sizeof(TID)) == -1)
		error_handling("read() error\n");
	printf("file data: %s \n", TID);
	close(fp);




	if (strcmp(EnterID, TID) == 0 && strcmp(EnterPASSWORD, TPASSWORD) == 0) {
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