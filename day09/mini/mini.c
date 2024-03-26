#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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
    time_t bTime;
    time_t rTime;
    struct BOOK* next;
} book;

typedef struct {
    book* head; // headNode로 구조체 변수는 node구조체의 멤버 변수 활용 가능
}headNode;

headNode* createHeadNode() {
    headNode* newHead = malloc(sizeof(headNode));
    newHead->head = NULL;       // newHead -> head 에 NUll값을 지정
    return  newHead;
}

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
}

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
        printf("6. 반납 체크\n");
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
            scanf("%s",bname);
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

        case 0: return 0;


        default:
            printf("잘못 입력하였습니다.\n");
            break;
        }
    }
    return 0;
}