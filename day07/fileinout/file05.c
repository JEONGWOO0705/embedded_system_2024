#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

void main() {
	int fd1, fd2;
	char str[] = "Wonderful day!";
	char buf[1024];

	fd1 = open("mytest.txt", O_RDWR| O_CREAT | O_TRUNC, 600);
 // 600 은 읽고 쓰는 권한 (2진수)
 // 700 은 읽고 쓰고 실행하는권한(2진수)

	if (fd1 < 0) {
		printf("Open Error");
	}
	if (write(fd1, str, strlen(str)) < 0) {
		printf("Write Error");
	}
	if (read(fd1, buf, 1024) < 0) {
		printf("Read Error");
	}

	fd2 = open("mytest_Copy.txt", O_RDWR | O_CREAT | O_TRUNC, 600);
	if (fd2 < 0) printf("Open Error");
	if (write(fd2, buf, strlen(buf)) < 0) printf("Writh Error");


	printf("%s\n", buf);
	close(fd1);
	close(fd2);






}