#include<stdio.h>

#define Q_SIZE 10

void enqueue(int *queue[],int *_rear, int _data) {	// 배열은 주소다!!!
	
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
	&rear 으로 설정하는 이유 (함수에서 *_rear로 설정하는 이유)
	- 메인의 rear 값을 복사하여 _rear이 받고 +1 되는 것은 메인의 rear 값이 아니라
	- 함수의 _rear 값이 올라감.
	- &rear 로 주소값을 올려주면서 복사하는 값 또한 +1되게함
	*/


	enqueue(queue, &rear, 20);


}