// 연결 리스트로 구현

#include<stdio.h>
#include<string.h>
#define STACK_SZ 10


typedef struct STACK {
	int buf[STACK_SZ];
	int top;
}stack;

void push(stack*, int);
void pop(stack*, int);


void main() {
	stack st;
	st.top = -1;


	push(&st, 10);
	push(&st, 8);
	push(&st, 4);

}

void push(stack* ps, int val) {
	ps->top++;
	ps->buf[ps->top] = val;
	printf("%d 이 입력되었습니다.\n", val);
	printf("현재 TOP의 값 : %d \n", ps->top);
}
/*

*/
