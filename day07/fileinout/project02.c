#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 100

typedef struct BOOK {
	char name;
	int price;
}book;


void main() {
	int choice;

	while (choice == 5) {
		printf("***** 메뉴 *****\n");
		printf("1. 도서 등록	2. 도서 검색	3. 도서 삭제	4. 도서 출력	5. 종료\n");
		scanf("%d", choice);
	}



}