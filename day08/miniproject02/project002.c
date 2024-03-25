#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECUR_NO_WARNINGS
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
    char name[BUF_SIZE]; // 문자열을 저장할 배열로 변경
    char author[BUF_SIZE]; // 문자열을 저장할 배열로 변경
    char publisher[BUF_SIZE];
    int check;
    int price;
    int page;
    int Id;
    struct BOOK* next;
} book;

typedef struct {
    book* head; // headNode로 구조체 변수는 node구조체의 멤버 변수 활용 가능
}headNode;

headNode* createHeadNode(void) {
    headNode* newHead = malloc(sizeof(headNode));
    newHead->head = NULL;       // newHead -> head 에 NUll값을 지정
    return  newHead;
}

void ShowAllNode(headNode* pnode) {
    book* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        printf("---------------------------------------------\n");
        printf("책 제목 : %s\n", curr[i].name);
        printf("출판사 : % s\n", curr[i].publisher);
        printf("저자 : % s\n", curr[i].author);
        printf("책 ID : %d\n", curr[i].Id);
        printf("책 가격 : %d\n", curr[i].price);
        printf("책 페이지 : %d\n", curr[i].page);
        if (curr[i].check == TRUE) {
            printf("대여 상태 : 대여중\n");
        }
        else if (curr[i].check == FALSE) {
            printf("대여 상태 : 대여 가능\n");

        }
        printf("---------------------------------------------\n");
        curr = curr->next;
    }
}

void ShowNameNode(headNode* pnode, const char _name) {
    book* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        if (curr->name == _name) {
            printf("---------------------------------------------\n");
            printf("책 제목 : %s\n", curr[i].name);
            printf("출판사 : % s\n", curr[i].publisher);
            printf("저자 : % s\n", curr[i].author);
            printf("책 ID : %d\n", curr[i].Id);
            printf("책 가격 : %d\n", curr[i].price);
            printf("책 페이지 : %d\n", curr[i].page);
            if (curr[i].check == TRUE) {
                printf("대여 상태 : 대여중\n");
            }
            else if (curr[i].check == FALSE) {
                printf("대여 상태 : 대여 가능\n");

            }
            printf("---------------------------------------------\n");
            break;
        }   
        curr = curr->next;
    }
}
void ShowPublisherNode(headNode* pnode, const char _publisher) {
    book* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        if (curr->publisher == _publisher) {
            printf("---------------------------------------------\n");
            printf("책 제목 : %s\n", curr[i].name);
            printf("출판사 : % s\n", curr[i].publisher);
            printf("저자 : % s\n", curr[i].author);
            printf("책 ID : %d\n", curr[i].Id);
            printf("책 가격 : %d\n", curr[i].price);
            printf("책 페이지 : %d\n", curr[i].page);
            if (curr[i].check == TRUE) {
                printf("대여 상태 : 대여중\n");
            }
            else if (curr[i].check == FALSE) {
                printf("대여 상태 : 대여 가능\n");

            }
            printf("---------------------------------------------\n");
        }
        curr = curr->next;
    }
}
void ShowAuthorNode(headNode* pnode, const char _author) {
    book* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        if (curr->author == _author) {
            printf("---------------------------------------------\n");
            printf("책 제목 : %s\n", curr[i].name);
            printf("출판사 : % s\n", curr[i].publisher);
            printf("저자 : % s\n", curr[i].author);
            printf("책 ID : %d\n", curr[i].Id);
            printf("책 가격 : %d\n", curr[i].price);
            printf("책 페이지 : %d\n", curr[i].page);
            if (curr[i].check == TRUE) {
                printf("대여 상태 : 대여중\n");
            }
            else if (curr[i].check == FALSE) {
                printf("대여 상태 : 대여 가능\n");

            }
            printf("---------------------------------------------\n");
        }
        curr = curr->next;
    }
}



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

void inputData() {
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
}

book* searchData(headNode* pnode, const char* _name) {
    int count = 0;
    book* search = malloc(sizeof(book));
    search = pnode->head;
    while (search->next != NULL) {
        search = search->next;
        count += 1;
        if (search->name == _name) {
            count += 1;
            break;
        }
    }
    return search;
}

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

void selectFreeNode(headNode* pnode, const char* _name) {
    int count = 0;
    book* search = malloc(sizeof(book));
    book* pre_search = malloc(sizeof(book));
    pre_search = pnode->head;
    search = pnode->head;
    while (search->next != NULL) {
        search = search->next;
        count += 1;
        if (search->name== _name) {
            pre_search->next = search->next;
            free(search);
            break;
        }
        pre_search = pre_search->next;
    }

}



int main() {
    int choice;
    book books[BUF_SIZE];
    books->check = FALSE;

    int numBooks = 0;
    headNode* newhead = createHeadNode();



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

        case 2:
            printf("검색할 카테고리를 정하시오 \n");
            printf("1. 책 제목\n");
            printf("2. 출판사\n");
            printf("3. 저자\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("책의 제목을 입력해 주세요 \n");
                scanf("%s", &bname);
                ShowNameNode(newhead, bname);
            }
            else if (choice == 2) {
                printf("책의 출판사를 입력해 주세요 \n");
                scanf("%s", &bpublisher);
                ShowPublisherNode(newhead, bpublisher);
            }
            else if (choice == 3) {
                printf("책의 저자를 입력해 주세요 \n");
                scanf("%s", &bauthor);
                ShowAuthorNode(newhead, bauthor);
            }
            else {
                printf("잘못 선택 하셨습니다 \n");
            }

        case 3:
            printf("삭제할 책의 제목을 입력하세요. \n");
            scanf("%s", &bname);
            selectFreeNode(newhead, bname);

        case 4:
            printf("전체 도서를 출력하겠습니다.\n");
            ShowAllNode(newhead);

        case 5:
            printf("대여할 책의 제목을 입력해 주세요.\n");
            scanf("%s", &bname);

            book* _book = searchData(newhead, bname);
            _book->check = TRUE;

        case 0: break;
        default:
            printf("잘못 입력하였습니다.\n");
        }
    }