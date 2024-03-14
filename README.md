# embedded_system_2024
Iot 개발자 임베디드 시스템 학습 리포지토리

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



## 2일차
- 라즈베리 안에서 첫 코드 실행!!

  ![실행](https://raw.githubusercontent.com/JEONGWOO0705/embedded_system_2024/main/image/img001.jpg)

    - pi@raspi:~/Work/C $ gcc -o test test.c
        - test.c를 컴파일 하여 test라는 실행파일을 만들어라
    - pi@raspi:~/Work/C $ ./test
        - test를 실행해라

## 3일차
- C 언어 전체 복습 빠르게 하기!!
    - 별찍기
    - 노드 설정하기
        - 노드 전위 삽입
        - 노드 후위 삽입
        - 노드 전체 출력

       


