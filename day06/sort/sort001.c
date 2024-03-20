#include<stdio.h>

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

	int ary[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(ary) / sizeof(ary[0]);
	int first = 0;
	int last = size;
	int middle = 0;
	
	printf("인덱스 : %d\n",binarySearch(ary, 1, size));
}