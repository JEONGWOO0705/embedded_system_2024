#include<stdio.h>




void main() {

	int ary[] = {9,4,8,15,3,7,2,1 };
	//int ary[] = { 9,4 };
	// 오름차순으로 정렬해보기
	int size = sizeof(ary) / sizeof(int);
	int temp = 0;


	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (ary[j] > ary[j+1]) {
				temp = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = temp;
			}
		}
	}

	printf("%d\n", ary[0]);

	for (int i = 0; i < size; i++) {
		printf("%d\n", ary[i]);
	}
}

	