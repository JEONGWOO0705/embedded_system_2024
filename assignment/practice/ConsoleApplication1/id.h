/*
Filr : id.h
Created : 24-03-27
author : È²Á¤¿ì
*/


#ifndef ID_H
#define ID_H
#define _CRT_SECUR_NO_WARNINGS
#define BUF_SIZE 100

char msg[BUF_SIZE];
char BUF[BUF_SIZE];
char ID[BUF_SIZE];
char PASSWORD[BUF_SIZE];

char AddreddBook[BUF_SIZE];
char EnterID[BUF_SIZE];
char EnterPASSWORD[BUF_SIZE];
char IDmsg[100];
char Passwordmsg[100];
char ID[100];
char PASSWORD[100];

void error_handling(char* message);

void loadFileout(const char*);
void loadFilesave(const char* filename, char value[]);
void error_handling(char* message);
void makeFile(const char* filename, const char* value);












#endif  // ID_H