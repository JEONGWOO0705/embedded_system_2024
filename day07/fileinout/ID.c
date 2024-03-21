#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#define BUF_SIZE 100
void error_handling(char* message);

int fd;
char msg[BUF_SIZE];
char BUF[BUF_SIZE];
char ID[BUF_SIZE];
char PASSWORD[BUF_SIZE];
char AddreddBook[BUF_SIZE];
char EnterID[BUF_SIZE];
char EnterPASSWORD[BUF_SIZE];

void main() {

	printf("생성할 아이디를 입력하세요 : \n");
	scanf("%s", ID);

	printf("생성할 비밀번호를 입력하세요 : \n");
	scanf("%s", PASSWORD);

	printf("입력된 ID와 PASSWORD는 %s, %s 입니다. \n", ID, PASSWORD);

	FILE* fp = fopen("id.txt", "w");  // 파일 포인터

	if (fp == NULL) {
		fprintf(stderr, "Error");	// 파일 입출력에서 사용되는  printf함수
		// stderr 은 파일 디스크립트
		exit(1);
	}
	fprintf(fp, "%s", ID);		// 파일로 출력

	fclose(fp);

	FILE* pp = fopen("password.txt", "w");  // 파일 포인터

	if (pp == NULL) {
		fprintf(stderr, "Error");	// 파일 입출력에서 사용되는  printf함수
		// stderr 은 파일 디스크립트
		exit(1);
	}
	fprintf(pp, "%s", PASSWORD);		// 파일로 출력

	fclose(pp);
}