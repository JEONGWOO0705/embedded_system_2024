#include <stdio.h>
#include <stdlib.h>
void main() {
	char msg[20] = "File Test!!";

	FILE* fp = fopen("test.txt", "w");  // 파일 포인터
	
	if (fp == NULL) {
		fprintf(stderr, "Error");	// 파일 입출력에서 사용되는  printf함수
									// stderr 은 파일 디스크립트
		exit(1);
	}
	fprintf(fp, "%s", msg);		// 파일로 출력
	printf("%s", msg);

	fclose(fp);
}



