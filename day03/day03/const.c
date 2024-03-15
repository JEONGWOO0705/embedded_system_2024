#include<stdio.h>
void main() {
	const int i = 10;
	printf("i:%d\n", i);
	/*
	6   i = 20;
	7   printf("After i: %d",i);
	8
	9
   10   int* pi = &i;
   11   printf("*pi: %d\n",*pi);
   12   */
	const int* pi2 = &i;
	printf("*pi2 : %d \n", *pi2);

}

