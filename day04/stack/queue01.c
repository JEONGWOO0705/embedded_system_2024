#include<stdio.h>

#define Q_SIZE 10

void enqueue(int *queue[],int *_rear, int _data) {	// �迭�� �ּҴ�!!!
	
	if (_rear = Q_SIZE - 1) {
		printf("QUEUE OFF!! \n");
		return;
	}
	queue[++(*(_rear))] = _data;
}


void main() {

	int rear = -1;
	int front = -1;
	int queue[Q_SIZE];

	enqueue(queue, &rear, 10);
	/*
	&rear ���� �����ϴ� ���� (�Լ����� *_rear�� �����ϴ� ����)
	- ������ rear ���� �����Ͽ� _rear�� �ް� +1 �Ǵ� ���� ������ rear ���� �ƴ϶�
	- �Լ��� _rear ���� �ö�.
	- &rear �� �ּҰ��� �÷��ָ鼭 �����ϴ� �� ���� +1�ǰ���
	*/


	enqueue(queue, &rear, 20);


}