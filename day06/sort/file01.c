#include <stdio.h>
#include <stdlib.h>
void main() {
	char msg[20] = "File Test!!";

	FILE* fp = fopen("test.txt", "w");  // ���� ������
	
	if (fp == NULL) {
		fprintf(stderr, "Error");	// ���� ����¿��� ���Ǵ�  printf�Լ�
									// stderr �� ���� ��ũ��Ʈ
		exit(1);
	}
	fprintf(fp, "%s", msg);		// ���Ϸ� ���
	printf("%s", msg);

	fclose(fp);
}



