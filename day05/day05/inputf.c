#include<stdio.h>

void input() {
	static char str[10];
	static char* pstr = str;

	printf("�Է� : ");
	scanf("%s", str[10]);

	return pstr;
}