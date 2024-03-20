// ÀÌÁø Å½»ö
#include <stdio.h>


void binarySearch(int ary[], int target, int size) {
	int first = 0;
	int last = size;
	int middle = 0;
	while (first <= last) {
		middle = (first + last) / 2;
		if (target == ary[middle]) {
			printf("%d\n", ary[middle]);
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
	printf("ÀÎµ¦½º : %d", middle);
}
void main() {

	int ary[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int first = 0;
	int last = size;
	int middle = 0;
	binarySearch(ary, 1, size);
}