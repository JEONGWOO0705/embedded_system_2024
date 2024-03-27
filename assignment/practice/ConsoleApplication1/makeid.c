/*
File : makeid.c
Created : 2024-03-27
Author: Ȳ����
DESC : LinkedlistFinal.c�� �����ϱ� ���� ID, PASSWORD������ ���� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>

void makeFile(const char* filename, const char* value) {
	FILE * fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "������ �� �� �����ϴ�.\n");
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
		printf("1. ������ ���̵� ����\n");
		printf("2. ����\n");
		scanf("%d", &choice);
		
		if (choice == 1) {
			printf("������ ID�� �Է��ϼ���: ");
			scanf("%s", ID);
			
			printf("������ PASSWORD�� �Է��ϼ���: ");
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
