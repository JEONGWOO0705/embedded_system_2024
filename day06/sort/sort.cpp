// 이진 탐색
#include <stdio.h>
void SSort(int ary[], int size) {
	int temp = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (&ary[j] > &ary[j + 1]) {
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		printf("%d\n", ary[i]);
	}
}

int binarySearch(int ary[], int target, int size) {
	int first = 0;
	int last = size;
	int middle = 0;
	while (first <= last) {
		middle = (first + last) / 2;
		if (target == ary[middle]) {			
			break;
		}
		else {
			if (target > ary[middle]) {
				first = middle + 1;
			}
			else {
				last = middle - 1;
			}
		}
	}
	return middle;
}
void main() {

	int ary[] = { 4,7,82,1,2,6,4 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int first = 0;
	int last = size;
	int middle = 0;
	SSort(ary, size);
	//printf("인덱스 : %d\n",binarySearch(ary, 1, size));
}