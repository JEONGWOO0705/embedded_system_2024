#include <stdio.h>
#include <stdlib.h>
void main() {
	char ab[20];
	char msg[20] = "JEONGWOO";
	FILE * fp = fopen("HWANG.txt", "w");  // ���� ������
	if (fp == NULL) {
		fprintf(stderr, "Error");   // ���� ����¿��� ���Ǵ�  print>
					���� ��ũ��Ʈ
		exit(1);
	}
	fprintf(fp, "%s", msg);     // ���Ϸ� ���
	printf("%s", msg);
	fclose(fp);
	if ((fp = fopen("HWANG.txt", "r")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(1);

	}
	fscanf(fp, "%s", ab);// fp�� �ִ� ���ڸ� �о�ͼ� ab�� �����ض�
	printf("%s\n", ab);
	fclose(fp);
	FILE * pp = fopen("HWANGCOPY.txt", "w");  // ���� ������
	if (pp == NULL) {
		fprintf(stderr, "Error");   // ���� ����¿��� ���Ǵ�  print>

		// stderr �� ���� ��ũ��Ʈ
		exit(1);
	}
	fprintf(pp, "%s", ab);      // ���Ϸ� ���
	printf("%s", ab);
	fclose(pp);
}
