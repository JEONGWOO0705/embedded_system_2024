#include <stdio.h>
#include <stdlib.h>

void main() {
	char msg[100] = "Ȳ����, ����, 27��, �λ�";
	FILE* fp = fopen("info.txt", "w");  // ���� ������
	if (fp == NULL) {
		fprintf(stderr, "Error");   // ���� ����¿��� ���Ǵ�  print>
		exit(1);
	}
	fprintf(fp, "%s\n", msg);       // ���Ϸ� ���
	printf("%s\n", msg);
	printf("file descriptor: %d\n", fp);
	fclose(fp);
}

