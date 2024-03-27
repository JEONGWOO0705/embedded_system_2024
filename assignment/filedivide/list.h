
/*
Filr : list.h
Created : 24-03-26
author : È²Á¤¿ì
*/

#ifndef LIST_H
#define LIST_H

#define _CRT_SECURE_NO_WARNINGS
#define BUF_SIZE 100
#define TRUE 1
#define FALSE 0

char bname[BUF_SIZE];
char bauthor[BUF_SIZE];
char bpublisher[BUF_SIZE];
int bpage;
int bprice;
int bId;

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

#endif  // LIST_H