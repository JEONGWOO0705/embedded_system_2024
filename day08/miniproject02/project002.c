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
    char name[BUF_SIZE]; // ���ڿ��� ������ �迭�� ����
    char author[BUF_SIZE]; // ���ڿ��� ������ �迭�� ����
    char publisher[BUF_SIZE];
    int check;
    int price;
    int page;
    int Id;
    struct BOOK* next;
} book;

typedef struct {
    book* head; // headNode�� ����ü ������ node����ü�� ��� ���� Ȱ�� ����
}headNode;

headNode* createHeadNode(void) {
    headNode* newHead = malloc(sizeof(headNode));
    newHead->head = NULL;       // newHead -> head �� NUll���� ����
    return  newHead;
}

void ShowAllNode(headNode* pnode) {
    book* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        printf("---------------------------------------------\n");
        printf("å ���� : %s\n", curr[i].name);
        printf("���ǻ� : % s\n", curr[i].publisher);
        printf("���� : % s\n", curr[i].author);
        printf("å ID : %d\n", curr[i].Id);
        printf("å ���� : %d\n", curr[i].price);
        printf("å ������ : %d\n", curr[i].page);
        if (curr[i].check == TRUE) {
            printf("�뿩 ���� : �뿩��\n");
        }
        else if (curr[i].check == FALSE) {
            printf("�뿩 ���� : �뿩 ����\n");

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
            printf("å ���� : %s\n", curr[i].name);
            printf("���ǻ� : % s\n", curr[i].publisher);
            printf("���� : % s\n", curr[i].author);
            printf("å ID : %d\n", curr[i].Id);
            printf("å ���� : %d\n", curr[i].price);
            printf("å ������ : %d\n", curr[i].page);
            if (curr[i].check == TRUE) {
                printf("�뿩 ���� : �뿩��\n");
            }
            else if (curr[i].check == FALSE) {
                printf("�뿩 ���� : �뿩 ����\n");

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
            printf("å ���� : %s\n", curr[i].name);
            printf("���ǻ� : % s\n", curr[i].publisher);
            printf("���� : % s\n", curr[i].author);
            printf("å ID : %d\n", curr[i].Id);
            printf("å ���� : %d\n", curr[i].price);
            printf("å ������ : %d\n", curr[i].page);
            if (curr[i].check == TRUE) {
                printf("�뿩 ���� : �뿩��\n");
            }
            else if (curr[i].check == FALSE) {
                printf("�뿩 ���� : �뿩 ����\n");

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
            printf("å ���� : %s\n", curr[i].name);
            printf("���ǻ� : % s\n", curr[i].publisher);
            printf("���� : % s\n", curr[i].author);
            printf("å ID : %d\n", curr[i].Id);
            printf("å ���� : %d\n", curr[i].price);
            printf("å ������ : %d\n", curr[i].page);
            if (curr[i].check == TRUE) {
                printf("�뿩 ���� : �뿩��\n");
            }
            else if (curr[i].check == FALSE) {
                printf("�뿩 ���� : �뿩 ����\n");

            }
            printf("---------------------------------------------\n");
        }
        curr = curr->next;
    }
}



void pre_addNode(headNode* pnode, const char* name, const char* author,
    const char* publisher, int price, int page, int Id) {
    book* newnode = malloc(sizeof(book));

    newnode->next = pnode->head;// pnode -> head ->next�ϸ� �ȵ�
    // pnode -> head ������ �ؾ� �޸� �Ҵ��� ����
    pnode->head = newnode;
    strcpy(newnode->name, name);
    strcpy(newnode->author, author);
    strcpy(newnode->publisher, publisher);
    newnode->check = FALSE;
    newnode->price = price;
    newnode->page = page;
    newnode->Id = Id;
    printf("���ο� å�� �����Ǿ����ϴ�\n");
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
    book* curr = pnode->head; // pnode(head)�� next���� ������ִ� ���� �ƴ϶�
    // pnode->head �� ����Ǿ� �ִ�
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newnode;
}

void inputData() {
    printf("å�� ������ �Է��� �ּ��� : \n");
    scanf("%s", &bname); // ������ �������� ���� ���ڿ� �Է� �ޱ�

    printf("å�� ���ڸ� �Է��� �ּ��� : \n");
    scanf("%s", &bauthor);

    printf("å�� ���ǻ� �� �Է��� �ּ��� : \n");
    scanf("%s", &bpublisher);

    printf("å�� ID�� �Է��� �ּ��� : \n");
    scanf("%d", &bId);

    printf("å�� ������ �Է��� �ּ��� : \n");
    scanf("%d", &bprice);

    printf("å�� �������� �Է��� �ּ��� : \n");
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
        printf("������ ����\n");
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
        printf("***** �޴� *****\n");
        printf("1. ���� ���\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("5. �뿩 üũ\n");
        printf("0. ����\n");
        printf("��ȣ�� �Է��Ͻÿ� : \n");
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
            printf("�˻��� ī�װ��� ���Ͻÿ� \n");
            printf("1. å ����\n");
            printf("2. ���ǻ�\n");
            printf("3. ����\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("å�� ������ �Է��� �ּ��� \n");
                scanf("%s", &bname);
                ShowNameNode(newhead, bname);
            }
            else if (choice == 2) {
                printf("å�� ���ǻ縦 �Է��� �ּ��� \n");
                scanf("%s", &bpublisher);
                ShowPublisherNode(newhead, bpublisher);
            }
            else if (choice == 3) {
                printf("å�� ���ڸ� �Է��� �ּ��� \n");
                scanf("%s", &bauthor);
                ShowAuthorNode(newhead, bauthor);
            }
            else {
                printf("�߸� ���� �ϼ̽��ϴ� \n");
            }

        case 3:
            printf("������ å�� ������ �Է��ϼ���. \n");
            scanf("%s", &bname);
            selectFreeNode(newhead, bname);

        case 4:
            printf("��ü ������ ����ϰڽ��ϴ�.\n");
            ShowAllNode(newhead);

        case 5:
            printf("�뿩�� å�� ������ �Է��� �ּ���.\n");
            scanf("%s", &bname);

            book* _book = searchData(newhead, bname);
            _book->check = TRUE;

        case 0: break;
        default:
            printf("�߸� �Է��Ͽ����ϴ�.\n");
        }
    }