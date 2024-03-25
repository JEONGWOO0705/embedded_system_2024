# embedded_system_2024
Iot 개발자 임베디드 시스템 학습 리포지토리

### 모든 파일은 라즈베리 파일안에 있어서 마무리후 깃허브에 옮기자!!!

## 1일차
- 라즈베리 파이를 위한 사전 인터넷 설정
    - 공유기 ip주소 할당하기

     ![실행](https://raw.githubusercontent.com/JEONGWOO0705/embedded_system_2024/main/image/img003.jpg)

    - 할당한 ip주소를 통해 포트포워드 설정하기

     ![실행](https://raw.githubusercontent.com/JEONGWOO0705/embedded_system_2024/main/image/img002.jpg)


- 라즈베리 파이 환경 설정
    - sudo apt update
    - sudo apt upgrade -y
    - clear --->> 위에 3개 주기적으로 하기!!
    - sudo nano /etc/nanorc 를 통해 환경설정
- 환경 설정 
    - 편집기 : 코드 작업할때 사용 하는 프로그램(nano)
- 기본명령어 (C)
    - 기존 PC같이 사용하면 안된다.
    - 순서에 맞추어 사용(동작중에 다른 명령어 처리 안됨)
    - pwd : 자기 위치
    - ls : 현재 목록
    - ls -a: 숨겨진 목록까지 보여줌
    - ls -l: 디렉토리의 생성 일자까지 확인 가능
    - mkdir : 디렉토리 생성    ex) mkdir Work   --> Work라는 디렉토리 생성
    - rm -fr : 디렉토리 삭제   ex) rm -fr Work  --> Work라는 디렉토리 삭제
    - cd : change 디렉토리
    - 리눅스 c++
        - pico 파일이름.cpp -> 생성
        - g++ 파일이름.cpp -o 실행파일이름 -> 실행 전 실행파일 이름 저장
        - 실행파일 이름


## 2일차
- 라즈베리 안에서 첫 코드 실행!!

  ![실행](https://raw.githubusercontent.com/JEONGWOO0705/embedded_system_2024/main/image/img001.jpg)

    - pi@raspi:~/Work/C $ gcc -o test test.c
        - test.c를 컴파일 하여 test라는 실행파일을 만들어라
    - pi@raspi:~/Work/C $ ./test
        - test를 실행해라

## 3일차
- C 언어 전체 복습 빠르게 하기!!
    - 노드 설정하기
        - 노드 전위 삽입
        - 노드 후위 삽입
        - 노드 전체 출력
        - head 추가 함수 및 전체 코드 검사

## 4일차
- 노드 검색 코드 추가
- C의 자료구조
    - stack, queue 만들어보기

```c
void enqueue(int *queue[],int *_rear, int _data) {	// 배열은 주소다!!!
	
	if (_rear = Q_SIZE - 1) {
		printf("QUEUE OFF!! \n");
		return;
	}
	queue[++(*(_rear))] = _data;
}


void main() {

	int rear = -1;
	int front = -1;
	int queue[Q_SIZE];

	enqueue(queue, &rear, 10);
	/*
	&rear 으로 설정하는 이유 (함수에서 *_rear로 설정하는 이유)
	- 메인의 rear 값을 복사하여 _rear이 받고 +1 되는 것은 메인의 rear 값이 아니라
	- 함수의 _rear 값이 올라감.
	- &rear 로 주소값을 올려주면서 복사하는 값 또한 +1되게함
	*/
```
## 5일차 
- 배열 정렬
    - 순차정렬
    - 버블 정렬
- 배열안 원소 찾기 
- TCP/IP 소켓 프로그래밍 시작!
    - 파일 입출력

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    // 표준 입출력
    void main() {
	    char msg[20] = "File Test!!";

	    FILE* fp = fopen("test.txt", "w");  // 파일 포인터
	
	    if (fp == NULL) {
		    fprintf(stderr, "Error");	// 파일 입출력에서 사용되는  printf함수
									// stderr 은 파일 디스크립트
		    exit(1);
	    }
	    fprintf(fp, "%s", msg);		// 파일로 출력
	    printf("%s", msg);

	    fclose(fp);

        ////////////////////
    /// 리눅스 환경
    #include<stdio.h>
    #include<stdlib.h>
    #include<fcntl.h>
    #include<unistd.h>
    void error_handling(char* message);

    int main(void) {
        int fd;
        char buf[] = "Let's go !\n";
        fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
        if (fd == -1) {
            error_handling("open() error!");
        }
        printf("file descriptor : %d\n", fd);

        if (write(fd, buf, sizeof(buf)) == -1) {
            error_handling("write() error!");
        }
        close(fd);
        return 0;
    }

    void error_handling(char* message) {
        fputs(message, stderr);
        fputc('\n', stderr);
        exit(1);
    }
    }
    ```
## 6일차 
- 미니 프로젝트 시작!!
- ID , PASSWORD 생성 프로그램
- 프로그램을 통해 ID , PASSWORD가 저장되있는 txt파일을 생성
 ![ID 생성](https://raw.githubusercontent.com/JEONGWOO0705/embedded_system_2024/main/image/img004.jpg)

 