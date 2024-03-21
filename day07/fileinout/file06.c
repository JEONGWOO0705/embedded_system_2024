#include <stdio.h>
#include <stdlib.h>
void main() {
	char ab[20];
	char msg[20] = "JEONGWOO";
	FILE * fp = fopen("HWANG.txt", "w");  // 파일 포인터
	if (fp == NULL) {
		fprintf(stderr, "Error");   // 파일 입출력에서 사용되는  print>
					파일 디스크립트
		exit(1);
	}
	fprintf(fp, "%s", msg);     // 파일로 출력
	printf("%s", msg);
	fclose(fp);
	if ((fp = fopen("HWANG.txt", "r")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(1);

	}
	fscanf(fp, "%s", ab);// fp에 있는 문자를 읽어와서 ab에 저장해라
	printf("%s\n", ab);
	fclose(fp);
	FILE * pp = fopen("HWANGCOPY.txt", "w");  // 파일 포인터
	if (pp == NULL) {
		fprintf(stderr, "Error");   // 파일 입출력에서 사용되는  print>

		// stderr 은 파일 디스크립트
		exit(1);
	}
	fprintf(pp, "%s", ab);      // 파일로 출력
	printf("%s", ab);
	fclose(pp);
}
