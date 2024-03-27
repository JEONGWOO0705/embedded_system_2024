/*
File : makeid.c
Created : 2024-03-27
Author: 황정우
DESC : LinkedlistFinal.c를 실행하기 전에 ID, PASSWORD생성을 위한 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

void makeFile(const char* filename, const char* value) {
	FILE * fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없습니다.\n");
		exit(1);
	}
	fprintf(fp, "%s", value);
	fclose(fp);
	
}

int main() {
	char IDmsg[100];
	char Passwordmsg[100];
	char ID[100];
	char PASSWORD[100];
	int choice;
	
	while (1) {
		printf("1. 관리자 아이디 생성\n");
		printf("2. 종료\n");
		scanf("%d", &choice);
		
		if (choice == 1) {
			printf("생성할 ID를 입력하세요: ");
			scanf("%s", ID);
			
			printf("생성할 PASSWORD를 입력하세요: ");
			scanf("%s", PASSWORD);
			
			makeFile("id.txt", ID);
			makeFile("password.txt", PASSWORD);
			
		}
		else {
			break;
		}
	}
		return 0;
	
}
