// �迭�� ����
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
	printf("%d �� �迭�� �ԷµǾ����ϴ�.\n", data);
}

int pop() {
	if (isEmpty()) {
		printf("stack underflow !!\n");
		return -1;	// �Ϲ������� �߸��� ���� ��µ� ��� -1�� ǥ���Ѵ�.
	}
	return stack[top--];

}

int isFull() {
	if (top == STACK_SZ - 1) {
		return TRUE;		// 0�� �ƴϸ� ���̴�, 0�� �����̴�.
	}
	else {
		return FALSE;	// ���ʿ��� #define True 1, #define FALSE 0 �� �س��ұ� ������
						// int Ÿ���� �Լ������� return TRUE�� �����ϴ�
						// ������� return 1, return 0
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