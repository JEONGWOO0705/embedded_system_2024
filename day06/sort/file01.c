#include <stdio.h>
#include <stdlib.h>

void main() {
	char msg[100] = "황정우, 남자, 27살, 부산";
	FILE* fp = fopen("info.txt", "w");  // 파일 포인터
	if (fp == NULL) {
		fprintf(stderr, "Error");   // 파일 입출력에서 사용되는  print>
		exit(1);
	}
	fprintf(fp, "%s\n", msg);       // 파일로 출력
	printf("%s\n", msg);
	printf("file descriptor: %d\n", fp);
	fclose(fp);
}

