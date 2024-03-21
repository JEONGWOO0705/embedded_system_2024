#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 100

typedef struct BOOK {
    char name[BUF_SIZE]; // 문자열을 저장할 배열로 변경
    char author[BUF_SIZE]; // 문자열을 저장할 배열로 변경
    char publisher[BUF_SIZE];
    int price;
    int page;
    int Id;
} book;

int main() {
    int choice;
    book books[BUF_SIZE];
    char bname[BUF_SIZE];
    char bauthor[BUF_SIZE];
    char bpublisher[BUF_SIZE];
    int bpage;
    int bprice;
    int bId;
    int numBooks = 0;
 

    while (1) {
        printf("***** 메뉴 *****\n");
        printf("1. 도서 등록    2. 도서 검색    3. 도서 삭제    4. 도서 출력    5. 종료\n");
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
            printf("검색할 책의 제목을 입력해 주세요.\n");
            scanf("%s", &bname);
            for (int i = 0; i <= numBooks; i++) {
                if (strcmp(books[i].name, bname) == 0) {
                    printf("책 제목 : %s\n", books[i].name);
                    printf("출판사 : % s\n", books[i].publisher);
                    printf("저자 : % s\n", books[i].author);
                    printf("책 ID : %d\n", books[i].Id);
                    printf("책 가격 : %d\n", books[i].price);
                    printf("책 페이지 : %d\n", books[i].page);

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
            break;
        }
    }

    return 0;
}
