
/*
Filr : list.h
Created : 24-03-27
author : È²Á¤¿ì
*/

#ifndef MAIN_H
#define MAIN_H

#define _CRT_SECURE_NO_WARNINGS
#define BUF_SIZE 100
#define TRUE 1
#define FALSE 0

extern char bname[BUF_SIZE];
extern char bauthor[BUF_SIZE];
extern char bpublisher[BUF_SIZE];
extern int bId;
extern int bprice;
extern int bpage;


extern char msg[BUF_SIZE];
extern char BUF[BUF_SIZE];
extern char ID[BUF_SIZE];
extern char PASSWORD[BUF_SIZE];

extern char AddreddBook[BUF_SIZE];
extern char EnterID[BUF_SIZE];
extern char EnterPASSWORD[BUF_SIZE];
extern char IDmsg[100];
extern char Passwordmsg[100];

void error_handling(char* message);

void loadFileout(const char*);
void loadFilesave(const char* filename, char value[]);
void error_handling(char* message);
void makeFile(const char* filename, const char* value);


typedef struct BOOK {
    char name[BUF_SIZE];
    char author[BUF_SIZE];
    char publisher[BUF_SIZE];
    int check;
    int price;
    int page;
    int Id;
    struct BOOK* next;
} book;

typedef struct {
    book* head;
} headNode;

headNode* createHeadNode();
void ShowAllNode(headNode*);
void printBookInfo(book*);
void pre_addNode(headNode*, const char*, const char*, const char*, int, int, int);
void rearNode(headNode*, const char*, const char*, const char*, int, int, int);
void inputData();
book* searchNameData(headNode*, const char*);
book* searchPublisherData(headNode*, const char*);
book* searchAuthorData(headNode*, const char*);
void selectFreeNode(headNode*, const char*);
void allFreeNode(headNode*);
int menu(void);
#endif  // MAIN_H