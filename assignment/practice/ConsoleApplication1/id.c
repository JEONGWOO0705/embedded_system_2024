/*
Filr : id.c
Created : 24-03-27
author : 황정우
*/




#include "id.h"
#include <stdio.h>
#include <stdlib.h>

//파일 로드 코드
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

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void makeFile(const char* filename, const char* value) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }
    fprintf(fp, "%s", value);
    fclose(fp);

}