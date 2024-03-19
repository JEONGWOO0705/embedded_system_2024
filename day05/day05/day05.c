#include <stdio.h>
#include<stdlib.h>
#define QSIZE 10
typedef struct {
	int front;
	int rear;
	char queue[QSIZE];
}queue;

queue* create();
void enqueue(queue* q, char data);
void dequeue(queue* q);
void printQueue(queue* q);

void main() {
	queue* qa = create();
	enqueue(qa, 'A');
	enqueue(qa, 'B');
	enqueue(qa, 'C');
	dequeue(qa);
	dequeue(qa);
	printQueue(qa);
}


queue* create() {
	queue* que = malloc(sizeof(queue));
	if (que == NULL) {
		exit(1);
	}
	else {
		que->front = -1;
		que->rear = -1;
		return que;
	}
}

void enqueue(queue* q, char data) {
	if (q->rear >= QSIZE) {
		printf("overflow");
	}
	else {
		q->rear++;
		q->queue[q->rear] = data;
		printf("%c 값이 %d 번째 큐에 들어갔습니다.\n", q->queue[q->rear], q->rear);
	}
	
}

void dequeue(queue* q) {
	if (q->front == q->rear || q->front <-1) {
		printf("under flow");
	}
	else {
		q->front++;
		int deq;
		deq = q->queue[q->front];
		printf("%c 값이 큐에서 나왔습니다.\n", deq);
	}
	
}
/*

void printQueue(queue* q) {
	if (q->front == q->rear || q->front < -1) {
		printf("under flow");
	}
	else {
		for (int i = 0; i < q->rear; i++) {
			printf("queue[%d] = %c\n", i, q->queue[i]);
		}

	}
	
}

*/

void printQueue(queue* q) {
	for (int i = q->front+1; i <= q->rear; i++) {
		printf("queue[%d] = %c\n", i, q->queue[i]);
	}
}