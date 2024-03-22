#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct BOOK {
    char name[BUF_SIZE]; // 문자열을 저장할 배열로 변경
    char author[BUF_SIZE]; // 문자열을 저장할 배열로 변경
    char publisher[BUF_SIZE];
    int check;
    int price;
    int page;
    int Id;
    
} book;




void showBookInfo(book* books, int i) {

    printf("---------------------------------------------\n");
    printf("책 제목 : %s\n", books[i].name);
    printf("출판사 : % s\n", books[i].publisher);
    printf("저자 : % s\n", books[i].author);
    printf("책 ID : %d\n", books[i].Id);
    printf("책 가격 : %d\n", books[i].price);
    printf("책 페이지 : %d\n", books[i].page);
    if (books[i].check == TRUE) {
        printf("대여 상태 : 대여중\n");
    }
    else if (books[i].check == FALSE) {
        printf("대여 상태 : 대여 가능\n");

    }
    printf("---------------------------------------------\n");


    
}

int main() {
    int choice;
    book books[BUF_SIZE];
    books->check = FALSE;
    char bname[BUF_SIZE];
    char bauthor[BUF_SIZE];
    char bpublisher[BUF_SIZE];
    int bpage;
    int bprice;
    int bId;
    int numBooks = 0;



    while (1) {
        printf("***** 메뉴 *****\n");
        printf("1. 도서 등록\n");
        printf("2. 도서 검색\n");
        printf("3. 도서 삭제\n");
        printf("4. 도서 출력\n");
        printf("5. 대여 체크\n");
        printf("0. 종료\n");
        printf("번호를 입력하시오 : \n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("책의 제목을 입력해 주세요 : \n");
            scanf("%s", &bname); // 공백을 포함하지 않은 문자열 입력 받기

            printf("책의 저자를 입력해 주세요 : \n");
            scanf("%s", &bauthor);

            printf("책의 출판사 를 입력해 주세요 : \n");
            scanf("%s", &bpublisher);

            printf("책의 ID를 입력해 주세요 : \n");
            scanf("%d", &bId);

            printf("책의 가격을 입력해 주세요 : \n");
            scanf("%d", &bprice);

            printf("책의 페이지를 입력해 주세요 : \n");
            scanf("%d", &bpage);

            // books 배열에 책 정보 저장
            strcpy(books[numBooks].name, bname);
            strcpy(books[numBooks].author, bauthor);
            strcpy(books[numBooks].publisher, bpublisher);
            books[numBooks].Id = bId;
            books[numBooks].price = bprice;
            books[numBooks].page = bpage;
            numBooks += 1; // 등록된 책의 수 증가
        }
        else if (choice == 2) {
            printf("검색할 카테고리를 정하시오 \n");
            printf("1. 책 제목\n");
            printf("2. 출판사\n");
            printf("3. 저자\n");
            printf("4. ID\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("검색할 책의 제목을 입력해 주세요.\n");
                scanf("%s", &bname);
                for (int i = 0; i <= numBooks; i++) {
                    if (strcmp(books[i].name, bname) == 0) {
                        showBookInfo(books, i);
                    }
                }
            }
            else if (choice == 2) {
                printf("검색할 책의 출판사를 입력해 주세요.\n");
                scanf("%s", &bpublisher);
                for (int i = 0; i <= numBooks; i++) {
                    if (strcmp(books[i].publisher, bpublisher) == 0) {
                        showBookInfo(books, i);
                    }
                }
            }
            else if (choice == 3) {
                printf("검색할 책의 저자 입력해 주세요.\n");
                scanf("%s", &bauthor);
                for (int i = 0; i <= numBooks; i++) {
                    if (strcmp(books[i].author, bauthor) == 0) {
                        showBookInfo(books, i);
                    }
                }
            }
            else if (choice == 4) {
                printf("검색할 책의 ID 입력해 주세요.\n");
                scanf("%s", &bauthor);
                for (int i = 0; i <= numBooks; i++) {
                    if (books[i].Id == bId) {
                        showBookInfo(books, i);
                    }
                }
            }
        }
        else if (choice == 3) {
            int found = 0;
            printf("삭제할 책의 제목을 입력해 주세요.\n");

            scanf("%s", &bname);

            for (int i = 0; i < numBooks; i++) {
                if (strcmp(books[i].name, bname) == 0) {
                    // 해당 책을 찾으면 삭제
                    for (int j = i; j < numBooks; j++) {
                        if (j == numBooks) {
                            strcpy(books[j].name, NULL);
                            strcpy(books[j].publisher, NULL);
                            strcpy(books[j].author, NULL);
                            books[j].Id = 0;
                            books[j].price = 0;
                            books[j].page = 0;
                            numBooks -= 1;
                        }
                        strcpy(books[j].name, books[j + 1].name);
                        strcpy(books[j].publisher, books[j + 1].publisher);
                        strcpy(books[j].author, books[j + 1].author);
                        books[j].Id = books[j + 1].Id;
                        books[j].price = books[j + 1].price;
                        books[j].page = books[j + 1].page;
                    }
                    numBooks--; // 책의 수를 감소
                    found = 1;
                    printf("책이 성공적으로 삭제되었습니다.\n");

                }
            }
            if (!found) {
                printf("해당 책을 찾을 수 없습니다.\n");
            }


        }

        else if (choice == 4) {
            if (numBooks >= 1) {
                printf("전체 책을 조회 하겠습니다.");
                for (int i = 0; i < numBooks; i++) {
                    printf("책 제목 : %s\n", books[i].name);
                    printf("책 출판사 : %s\n", books[i].publisher);
                    printf("저자 : % s\n", books[i].author);
                    printf("책 ID : %d\n", books[i].Id);
                    printf("책 가격 : %d\n", books[i].price);
                    printf("책 페이지 : %d\n", books[i].page);
                }
            }

            else if (numBooks < 1) {
                printf("조회할 책이 없습니다.\n");
            }
        }

        else if (choice == 5) {
            int find = 0;
            printf("대여 체크를 할 책의 제목을 입력해주세요 : \n");
            scanf("%s", &bname);
            for (int i = 0; i <= numBooks; i++) {
                if (strcmp(books[i].name, bname) == 0) {
                    printf("'%s' 이 대여중 입니까? \n ", books->name);
                    printf(" 1. Yes\n");
                    printf(" 2. No\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        books[i].check = TRUE;
                    }
                    else if (choice == 2) {
                        books[i].check = FALSE;
                    }
                    else {
                        printf("잘못 선택하셨습니다.\n");
                        return FALSE;
                    }
                    find = 1;
                }
            }
            if (find == 0) {
                printf("책을 찾지 못했습니다.\n");
                return FALSE;
            }
        }


        else if (choice == 0) {
            break;
        }
    }

    return 0;
}
