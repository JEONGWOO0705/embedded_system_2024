#include<stdio.h>


int lSearch(int ary[], int _size, int num) {
	int searchnum = NULL;
	for (int i = 0; i < _size - 1; i++) {
		if (ary[i] == num) {
			searchnum = i;
		}
	}
	if (searchnum == NULL) {
		return -1;
	}
	
}

void main() {

	int ary[] = { 3,5,2,4,7,9,8,1 };
	int size = sizeof(ary) / sizeof(int);
	int ridx;

	ridx = lSearch(ary, size, 9);
	if (ridx == -1) {
		printf("ã�� ���Ұ� �����ϴ�.\n");
	}
	else {
		printf("ã�� �ε��� : %d", ridx);
	}

	
}

