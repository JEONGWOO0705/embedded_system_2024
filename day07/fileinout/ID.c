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

	printf("������ ���̵� �Է��ϼ��� : \n");
	scanf("%s", ID);

	printf("������ ��й�ȣ�� �Է��ϼ��� : \n");
	scanf("%s", PASSWORD);

	printf("�Էµ� ID�� PASSWORD�� %s, %s �Դϴ�. \n", ID, PASSWORD);

	FILE* fp = fopen("id.txt", "w");  // ���� ������

	if (fp == NULL) {
		fprintf(stderr, "Error");	// ���� ����¿��� ���Ǵ�  printf�Լ�
		// stderr �� ���� ��ũ��Ʈ
		exit(1);
	}
	fprintf(fp, "%s", ID);		// ���Ϸ� ���

	fclose(fp);

	FILE* pp = fopen("password.txt", "w");  // ���� ������

	if (pp == NULL) {
		fprintf(stderr, "Error");	// ���� ����¿��� ���Ǵ�  printf�Լ�
		// stderr �� ���� ��ũ��Ʈ
		exit(1);
	}
	fprintf(pp, "%s", PASSWORD);		// ���Ϸ� ���

	fclose(pp);
}