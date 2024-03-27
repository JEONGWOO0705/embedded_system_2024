/*
Filr : LinkedListMain.c
Created : 24-03-27
author : 황정우
*/

#include<stdio.h>
#include"list.h"
#include"id.h"
#define _CRT_SECUR_NO_WARNINGS


// 초기 관리자 ID : aa
// 초기 관리자 PASSWORD : bb


int main() {
    int choice;
    book books[BUF_SIZE];
    books->check = FALSE;

    int numBooks = 0;
    headNode* newhead = createHeadNode();

    loadFilesave("id.txt", ID);
    loadFilesave("password.txt", PASSWORD);
    printf("관리자 프로그램 ID와 PASSWORD를 입력해 주세요\n");


    printf("아이디를 입력하세요 : \n");
    scanf("%s", EnterID);

    printf("비밀번호를 입력하세요 : \n");
    scanf("%s", EnterPASSWORD);

    while (TRUE) {
        if (strcmp(ID, EnterID) == 0 && strcmp(PASSWORD, EnterPASSWORD) == 0) {
            printf("로그인 성공 하였습니다.\n");
            while (1) {
                printf("***** 메뉴 *****\n");
                printf("1. 도서 등록\n");
                printf("2. 도서 검색\n");
                printf("3. 도서 삭제\n");
                printf("4. 도서 출력\n");
                printf("5. 대여 체크\n");
                printf("6. 반납 체크\n");
                printf("7. 아이디 변경\n");
                printf("0. 종료\n");
                printf("번호를 입력하시오 : \n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    if (newhead->head == NULL) {
                        inputData();
                        pre_addNode(newhead, bname, bauthor, bpublisher, bprice, bpage, bId);
                    }
                    else {
                        inputData();
                        rearNode(newhead, bname, bauthor, bpublisher, bprice, bpage, bId);
                    }
                    break;

                    break;

                case 2:
                    printf("검색할 카테고리를 정하시오 \n");
                    printf("1. 책 제목\n");
                    printf("2. 출판사\n");
                    printf("3. 저자\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("책의 제목을 입력해 주세요 : \n");
                        scanf("%99s", bname);
                        book* found = searchNameData(newhead, bname);
                        if (found != NULL) {
                            printBookInfo(found);
                        }
                    }
                    else if (choice == 2) {
                        printf("책의 출판사를 입력해 주세요 : \n");
                        scanf("%99s", bpublisher);
                        book* found = searchPublisherData(newhead, bpublisher);
                        if (found != NULL) {
                            printBookInfo(found);
                        }
                    }
                    else if (choice == 3) {
                        printf("책의 저자 입력해 주세요 : \n");
                        scanf("%99s", bauthor);
                        book* found = searchAuthorData(newhead, bauthor);
                        if (found != NULL) {
                            printBookInfo(found);
                        }
                    }
                    break;

                case 3:
                    printf("삭제할 책의 제목을 입력하세요. \n");
                    scanf("%s", bname);
                    book* del = searchNameData(newhead, bname);
                    if (del != NULL) {
                        selectFreeNode(newhead, bname);
                        printf("책이 삭제되었습니다.\n");
                        break;
                    }
                    else {
                        break;
                    }

                case 4:
                    printf("전체 도서를 출력하겠습니다.\n");
                    ShowAllNode(newhead);
                    break;
                case 5:
                    printf("대여할 책의 제목을 입력해 주세요.\n");
                    scanf("%s", bname);

                    book* _book = searchNameData(newhead, bname);

                    if (_book != NULL) {
                        if (_book->check == FALSE) {
                            _book->check = TRUE;
                            printf("책이 대여 되었습니다.\n");
                        }
                        else if (_book->check == TRUE) {
                            printf("해당 책은 이미 대여 되었습니다.\n");

                        }
                        break;
                    }

                    else {
                        break;
                    }


                case 6:
                    printf("반납할 책의 제목을 입력해 주세요\n");
                    scanf("%s", bname);

                    book* k = searchNameData(newhead, bname);


                    if (k != NULL) {
                        if (k->check == TRUE) {
                            k->check = FALSE;
                            printf("책이 반납 되었습니다.\n");
                        }
                        else if (k->check == FALSE) {
                            printf("해당 책은 이미 반납 되었습니다.\n");
                        }
                        break;
                    }
                    else {
                        break;
                    }

                case 7:
                    printf("1. 관리자 아이디 변경\n");
                    printf("2. 종료\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("생성할 ID를 입력하세요: ");
                        scanf("%s", ID);

                        printf("생성할 PASSWORD를 입력하세요: ");
                        scanf("%s", PASSWORD);

                        makeFile("id.txt", ID);
                        makeFile("password.txt", PASSWORD);
                        break;
                    }
                    else {
                        break;
                    }
                case 0: return 0;


                default:
                    printf("잘못 입력하였습니다.\n");
                    break;
                }
            }
        }
        else {
            printf("비밀 번호가 틀립니다.\n");
            printf("\n");
            printf("종료하시겠습니까? \n");
            printf("1번을 누르면 종료됩니다. \n");
            printf("아니라면 다른 번호를 입력해 주세요.\n");
            scanf("%d", &choice);
            if (choice == 1) {
                return 0;
            }
            else {
                printf("관리자 프로그램 ID와 PASSWORD를 입력해 주세요\n");
                printf("아이디를 입력하세요 : \n");
                scanf("%s", EnterID);

                printf("비밀번호를 입력하세요 : \n");
                scanf("%s", EnterPASSWORD);
            }

        }
    }
    
   

    return 0;
}
