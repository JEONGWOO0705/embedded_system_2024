// 연결 리스트로 구현

#include<stdio.h>
#include<string.h>
#define STACK_SZ 10


typedef struct STACK {
	int buf[STACK_SZ];
	int top;
}stack;

void push(stack*, int);
int pop(stack*);
int isEmpty(stack*);
int isFull(stack*);


void main() {
	stack st;	// stack 구조체 생성
	st.top = -1;


	push(&st, 10); // &사용하는 이유는 해당 함수에 스택구조체의 주소를 전달하기 위해서
	push(&st, 8);
	push(&st, 4);
	pop(&st);
	pop(&st);
	pop(&st);
	pop(&st);

}

void push(stack* ps, int val) {
	if (isFull(ps)) {
		printf("overflow!!\n");
	}
	else {
		ps->top++;
		ps->buf[ps->top] = val;
		printf("%d 이 입력되었습니다.\n", val);
		printf("현재 TOP의 값 : %d \n", ps->top);
	}
	
}

int pop(stack* ps) {
	if (isEmpty(ps)){
		printf("under flow!!\n");
		return -1;
	}
	else {
		printf("추출된 값 : %d \n", ps->buf[ps->top]);
		ps->top--;
	}
	
}

int isEmpty(stack*ps) {
	if (ps->top <= -1) {
		return 1;
	}
	else return 0;
}

int isFull(stack* ps) {
	if (ps->top == STACK_SZ - 1) {
		return 1;
	}
	else return 0;
}