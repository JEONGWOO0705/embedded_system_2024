/*
Filr : list.c
Created : 24-03-27
author : 황정우
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

headNode* createHeadNode() {
    headNode* newHead = malloc(sizeof(headNode));
    if (newHead == NULL) {
        printf("메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }
    newHead->head = NULL;
    return newHead;
}
// 모든 데이터 출력 코드 
void ShowAllNode(headNode* pnode) {
    book* curr = pnode->head;
    while (curr != NULL) {
        printf("---------------------------------------------\n");
        printf("책 제목 : %s\n", curr->name);
        printf("출판사 : %s\n", curr->publisher);
        printf("저자 : %s\n", curr->author);
        printf("책 ID : %d\n", curr->Id);
        printf("책 가격 : %d\n", curr->price);
        printf("책 페이지 : %d\n", curr->page);
        if (curr->check == TRUE) {
            printf("대여 상태 : 대여중\n");
        }
        else if (curr->check == FALSE) {
            printf("대여 상태 : 대여 가능\n");
        }
        printf("---------------------------------------------\n");
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("조회되는 책이 없습니다.\n");
    }
}   // 모든 데이터 출력 코드
// 지정 데이터 출력 코드
void printBookInfo(book* curr) {
    printf("---------------------------------------------\n");
    printf("책 제목 : %s\n", curr->name);
    printf("출판사 : %s\n", curr->publisher);
    printf("저자 : %s\n", curr->author);
    printf("책 ID : %d\n", curr->Id);
    printf("책 가격 : %d\n", curr->price);
    printf("책 페이지 : %d\n", curr->page);
    if (curr->check == TRUE) {
        printf("대여 상태 : 대여중\n");
    }
    else if (curr->check == FALSE) {
        printf("대여 상태 : 대여 가능\n");
    }
    printf("---------------------------------------------\n");
}

// 데이터 추가 코드
void pre_addNode(headNode* pnode, const char* name, const char* author,
    const char* publisher, int price, int page, int Id) {
    book* newnode = malloc(sizeof(book));

    newnode->next = pnode->head;// pnode -> head ->next하면 안됨
    // pnode -> head 지정을 해야 메모리 할당을 받음
    pnode->head = newnode;
    strcpy(newnode->name, name);
    strcpy(newnode->author, author);
    strcpy(newnode->publisher, publisher);
    newnode->check = FALSE;
    newnode->price = price;
    newnode->page = page;
    newnode->Id = Id;
    printf("새로운 책이 생성되었습니다\n");
}
// 데이터 추가 코드(후입)
void rearNode(headNode* pnode, const char* name, const char* author,
    const char* publisher, int price, int page, int Id) {
    book* newnode = malloc(sizeof(book));
    strcpy(newnode->name, name);
    strcpy(newnode->author, author);
    strcpy(newnode->publisher, publisher);
    newnode->check = FALSE;
    newnode->price = price;
    newnode->page = page;
    newnode->Id = Id;
    newnode->next = NULL;
    book* curr = pnode->head; // pnode(head)에 next값이 저장되있는 것이 아니라
    // pnode->head 에 저장되어 있다
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newnode;
}
// 데이터 입력 코드
void inputData() {
    printf("책의 제목을 입력해 주세요 : \n");
    scanf("%99s", bname); // 버퍼 오버플로우 방지를 위해 최대 길이 지정

    printf("책의 저자를 입력해 주세요 : \n");
    scanf("%99s", bauthor); // 버퍼 오버플로우 방지를 위해 최대 길이 지정

    printf("책의 출판사를 입력해 주세요 : \n");
    scanf("%99s", bpublisher); // 버퍼 오버플로우 방지를 위해 최대 길이 지정

    printf("책의 ID를 입력해 주세요 : \n");
    while (scanf("%d", &bId) != 1) { // 잘못된 입력 형식 방지
        printf("올바른 형식으로 다시 입력해 주세요.\n");
        while (getchar() != '\n'); // 입력 버퍼 비우기
    }

    printf("책의 가격을 입력해 주세요 : \n");
    while (scanf("%d", &bprice) != 1 || bprice < 0) { // 잘못된 입력 값 및 음수 가격 방지
        printf("올바른 가격을 양수로 다시 입력해 주세요.\n");
        while (getchar() != '\n'); // 입력 버퍼 비우기
    }

    printf("책의 페이지를 입력해 주세요 : \n");
    while (scanf("%d", &bpage) != 1 || bpage < 0) { // 잘못된 입력 값 및 음수 페이지 방지
        printf("올바른 페이지 수를 양수로 다시 입력해 주세요.\n");
        while (getchar() != '\n'); // 입력 버퍼 a비우기
    }
}

// 책 제목으로 데이터 찾기
book* searchNameData(headNode* pnode, const char* _name) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->name, _name) == 0) {
            return search; // 검색된 책을 찾으면 해당 노드를 반환
        }
        search = search->next;
    }
    printf("책을 검색할 수 없습니다.\n");
    return NULL;

}

// 책 출판사로 데이터 찾기
book* searchPublisherData(headNode* pnode, const char* _pub) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->publisher, _pub) == 0) {
            return search; // 검색된 책을 찾으면 해당 노드를 반환
        }
        search = search->next;
    }
    printf("책을 검색할 수 없습니다.\n");
    return NULL;
}
// 책 작가로 데이터 찾기
book* searchAuthorData(headNode* pnode, const char* _author) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->author, _author) == 0) {
            return search; // 검색된 책을 찾으면 해당 노드를 반환
        }
        search = search->next;
    }
    printf("책을 검색할 수 없습니다.\n");
    return NULL; // 검색된 책이 없을 경우 NULL 반환
}
//전체 데이터 삭제 코드
void allFreeNode(headNode* pnode) {
    book* curr = pnode->head;
    while (curr != NULL) {
        book* dn = curr;
        curr = curr->next;
        printf("데이터 삭제\n");
        free(dn);
    }
    pnode->head->next = NULL;
    printf("head -> next : %d,  head->data: %d \n", pnode->head->next, curr);
    free(pnode);
}
// 지정 데이터 삭제 코드
void selectFreeNode(headNode* pnode, const char* _name) {
    book* search = pnode->head;
    book* pre_search = NULL;

    // 첫 번째 노드가 삭제 대상인 경우
    if (strcmp(search->name, _name) == 0) {
        pnode->head = search->next;
        free(search);
        return;
    }

    // 그 외의 경우
    while (search != NULL) {
        if (strcmp(search->name, _name) == 0) {
            pre_search->next = search->next;
            free(search);
            return;
        }
        pre_search = search;
        search = search->next;
    }

    // 검색된 책이 없을 때
    printf("해당하는 책을 찾을 수 없습니다.\n");
}

