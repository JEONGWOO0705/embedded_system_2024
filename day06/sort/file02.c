// 리눅스 스타일

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
2#include<unistd.h>

void main() {

	char msg[] = "Linux Test!!";
	int fd;

	fd = open("test02.txt", O_CREAT | O_WRONLY);
	if (fd == -1) {
		printf("file open error");
		exit(1);
	}
	printf("file descriptor: %d\n", fd);

	if (write(fd, msg, sizeof(msg)) == -1) {
		printf("file write error");
	}
	close(fd);

}