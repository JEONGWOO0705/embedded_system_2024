
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char msg[20];
	FILE * fp;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(1);
	}
	fscanf(fp, "%s", msg);// fp�� �ִ� ���ڸ� �о�ͼ� msg�� �����ض�
	printf("%s\n", msg);
	fclose(fp);
}
