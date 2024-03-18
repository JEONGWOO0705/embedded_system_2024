// 배열로 구현
#include <stdio.h>
#define STACK_SZ 10
#define TRUE 1
#define FALSE 0

int stack[STACK_SZ];
int top = -1;

void push(int data);
int pop();
int isFull();
int isEmpty();

void main() {

	push(3);
	push(5);
	push(10);

	printf("%d \n", pop());
}


void push(int data) {
	// if(top == STACK_SZ -1){}
	if (isFull()) {	

		printf("stack overflow!!\n");
		return;
	}
	stack[++top] = data;
	printf("%d 이 배열에 입력되었습니다.\n", data);
}

int pop() {
	if (isEmpty()) {
		printf("stack underflow !!\n");
		return -1;	// 일반적으로 잘못된 값이 출력된 경우 -1을 표시한다.
	}
	return stack[top--];

}

int isFull() {
	if (top == STACK_SZ - 1) {
		return TRUE;		// 0이 아니면 참이다, 0은 거짓이다.
	}
	else {
		return FALSE;	// 위쪽에서 #define True 1, #define FALSE 0 을 해놓았기 때문에
						// int 타입의 함수에서도 return TRUE가 가능하다
						// 원래라면 return 1, return 0
	}
}
int isEmpty() {
	if (top <= -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}