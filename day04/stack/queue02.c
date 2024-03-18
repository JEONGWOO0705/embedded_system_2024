#include<stdio.h>

#define Q_SIZE 10

int rear = -1;
int front = -1;
int queue[Q_SIZE];

void enqueue(int _data) {	// �迭�� �ּҴ�!!!

	if (rear >= Q_SIZE - 1) {
		printf("QUEUE OFF!! \n");
		return;
	}
	queue[++rear] = _data;
}

int dequeue() {
	if (front == rear) {
		printf("QUEUE UnderFlow");
		return -1;
	}
	else {
		return queue[++front];
	}

}


void main() {
	enqueue(10);
	/*
	&rear ���� �����ϴ� ���� (�Լ����� *_rear�� �����ϴ� ����)
	- ������ rear ���� �����Ͽ� _rear�� �ް� +1 �Ǵ� ���� ������ rear ���� �ƴ϶�
	- �Լ��� _rear ���� �ö�.
	- &rear �� �ּҰ��� �÷��ָ鼭 �����ϴ� �� ���� +1�ǰ���
	*/


	enqueue(20);
	enqueue(30);

	printf("%d \n", dequeue()); // 10
	printf("%d \n", dequeue()); // 20



}