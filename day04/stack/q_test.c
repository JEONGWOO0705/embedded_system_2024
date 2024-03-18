#include <stdio.h>

void main() {
	int ary[] = {1,2,3,4,5,6,7,8,9,10 };
	int queue[20];
	int rear = 0, front = 0;	// 입구(rear)로 삽입하고  , 출구(front)를 통해서 삭제4
	int size = sizeof(ary) / sizeof(ary[0]);
	//printf("%d", sizeof(ary)/sizeof(int));
	
	/*
	for (int i = 0; i < size; i++) {
		queue[i] = ary[i];
		rear += 1;
		printf("%d \n", queue[i]);
	}

	for (int i = 0; i < size; i++) {
		printf("queue[%d] = %d\n", i, queue[i]);
	}
	*/
	for (rear; rear < size; rear++) {
		queue[rear] = ary[rear];
		printf("%d \n", queue[rear]);
	}
	
	for (front ; front < size; front++) {
		printf("queue[%d] = %d\n", front, queue[front]);
	}
}