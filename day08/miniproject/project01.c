/*
Filr : project01.c (파일 입출력)
Created : 24-03-26
author : 황정우
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 100

char msg[BUF_SIZE];
char BUF[BUF_SIZE];
char ID[BUF_SIZE];
char PASSWORD[BUF_SIZE];

char AddreddBook[BUF_SIZE];
char EnterID[BUF_SIZE];
char EnterPASSWORD[BUF_SIZE];
void error_handling(char* message);

void loadFileout(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error_handling("fopen() error\n");
    }
    while (fgets(BUF, sizeof(BUF), file) != NULL) {
        printf("file data: %s", BUF);
    }
    fclose(file);
}

void loadFilesave(const char* filename, char value[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error_handling("fopen() error\n");
    }
    fgets(value, BUF_SIZE, file);
    fclose(file);
}


int main() {
    loadFilesave("id.txt", ID);
    loadFilesave("password.txt", PASSWORD);
    printf("본인의 정보가 저장된 파일을 오픈할려면 ID와 PASSWORD를 입력해 주세요\n");


    printf("아이디를 입력하세요 : \n");
    scanf("%s", EnterID);

    printf("비밀번호를 입력하세요 : \n");
    scanf("%s", EnterPASSWORD);

    if (strcmp(ID, EnterID) == 0 && strcmp(PASSWORD, EnterPASSWORD) == 0) {
        loadFileout("myinfo.txt");
    }
    else {
        printf("등록된 ID 혹은 PASSWORD가 틀렸습니다.\n");
    }


    return 0;
}


void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
