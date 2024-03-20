
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
	fscanf(fp, "%s", msg);// fp에 있는 문자를 읽어와서 msg에 저장해라
	printf("%s\n", msg);
	fclose(fp);
}
