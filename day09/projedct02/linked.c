/*
Filr : LinkedList 
Created : 24-03-26
author : Ȳ����
DESC : ���� ����� ������� ���α׷� �۵�
*/


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

headNode* createHeadNode() {
    headNode* newHead = malloc(sizeof(headNode));
    newHead->head = NULL;       // newHead -> head �� NUll���� ����
    return  newHead;
}

void ShowAllNode(headNode* pnode) {
    book* curr = pnode->head;
    while (curr != NULL) {
        printf("---------------------------------------------\n");
        printf("å ���� : %s\n", curr->name);
        printf("���ǻ� : %s\n", curr->publisher);
        printf("���� : %s\n", curr->author);
        printf("å ID : %d\n", curr->Id);
        printf("å ���� : %d\n", curr->price);
        printf("å ������ : %d\n", curr->page);
        if (curr->check == TRUE) {
            printf("�뿩 ���� : �뿩��\n");
        }
        else if (curr->check == FALSE) {
            printf("�뿩 ���� : �뿩 ����\n");
        }
        printf("---------------------------------------------\n");
        curr = curr->next;
    }
}

void printBookInfo(book* curr) {
    printf("---------------------------------------------\n");
    printf("å ���� : %s\n", curr->name);
    printf("���ǻ� : %s\n", curr->publisher);
    printf("���� : %s\n", curr->author);
    printf("å ID : %d\n", curr->Id);
    printf("å ���� : %d\n", curr->price);
    printf("å ������ : %d\n", curr->page);
    if (curr->check == TRUE) {
        printf("�뿩 ���� : �뿩��\n");
    }
    else if (curr->check == FALSE) {
        printf("�뿩 ���� : �뿩 ����\n");
    }
    printf("---------------------------------------------\n");
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
    scanf("%99s", bname); // ���� �����÷ο� ������ ���� �ִ� ���� ����

    printf("å�� ���ڸ� �Է��� �ּ��� : \n");
    scanf("%99s", bauthor); // ���� �����÷ο� ������ ���� �ִ� ���� ����

    printf("å�� ���ǻ縦 �Է��� �ּ��� : \n");
    scanf("%99s", bpublisher); // ���� �����÷ο� ������ ���� �ִ� ���� ����

    printf("å�� ID�� �Է��� �ּ��� : \n");
    while (scanf("%d", &bId) != 1) { // �߸��� �Է� ���� ����
        printf("�ùٸ� �������� �ٽ� �Է��� �ּ���.\n");
        while (getchar() != '\n'); // �Է� ���� ����
    }

    printf("å�� ������ �Է��� �ּ��� : \n");
    while (scanf("%d", &bprice) != 1 || bprice < 0) { // �߸��� �Է� �� �� ���� ���� ����
        printf("�ùٸ� ������ ����� �ٽ� �Է��� �ּ���.\n");
        while (getchar() != '\n'); // �Է� ���� ����
    }

    printf("å�� �������� �Է��� �ּ��� : \n");
    while (scanf("%d", &bpage) != 1 || bpage < 0) { // �߸��� �Է� �� �� ���� ������ ����
        printf("�ùٸ� ������ ���� ����� �ٽ� �Է��� �ּ���.\n");
        while (getchar() != '\n'); // �Է� ���� ����
    }
}


book* searchNameData(headNode* pnode, const char* _name) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->name, _name) == 0) {
            return search; // �˻��� å�� ã���� �ش� ��带 ��ȯ
        }
        search = search->next;
    }
    return NULL; // �˻��� å�� ���� ��� NULL ��ȯ
}


book* searchPublisherData(headNode* pnode, const char* _pub) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->publisher, _pub) == 0) {
            return search; // �˻��� å�� ã���� �ش� ��带 ��ȯ
        }
        search = search->next;
    }
    return NULL; // �˻��� å�� ���� ��� NULL ��ȯ
}

book* searchAuthorData(headNode* pnode, const char* _author) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->author, _author) == 0) {
            return search; // �˻��� å�� ã���� �ش� ��带 ��ȯ
        }
        search = search->next;
    }
    return NULL; // �˻��� å�� ���� ��� NULL ��ȯ
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
    book* search = pnode->head;
    book* pre_search = NULL;

    // ù ��° ��尡 ���� ����� ���
    if (strcmp(search->name, _name) == 0) {
        pnode->head = search->next;
        free(search);
        return;
    }

    // �� ���� ���
    while (search != NULL) {
        if (strcmp(search->name, _name) == 0) {
            pre_search->next = search->next;
            free(search);
            return;
        }
        pre_search = search;
        search = search->next;
    }

    // �˻��� å�� ���� ��
    printf("�ش��ϴ� å�� ã�� �� �����ϴ�.\n");
}




void main() {
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
        printf("6. �ݳ� üũ\n");
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

            break;

        case 2:
            printf("�˻��� ī�װ��� ���Ͻÿ� \n");
            printf("1. å ����\n");
            printf("2. ���ǻ�\n");
            printf("3. ����\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("å�� ������ �Է��� �ּ��� : \n");
                scanf("%99s", bname);
                book* found = searchNameData(newhead, bname);
                printBookInfo(found);

            }
            else if (choice == 2) {
                printf("å�� ���ǻ縦 �Է��� �ּ��� : \n");
                scanf("%99s", bpublisher);
                book* found = searchPublisherData(newhead, bpublisher);
                printBookInfo(found);
            }
            else if (choice == 3) {
                printf("å�� ���� �Է��� �ּ��� : \n");
                scanf("%99s", bauthor);
                book* found = searchAuthorData(newhead, bauthor);
                printBookInfo(found);
            }
            else {
                printf("�߸� ���� �ϼ̽��ϴ� \n");
            }
            break;

        case 3:
            printf("������ å�� ������ �Է��ϼ���. \n");
            scanf("%s", bname);
            selectFreeNode(newhead, &bname);
            break;

        case 4:
            printf("��ü ������ ����ϰڽ��ϴ�.\n");
            ShowAllNode(newhead);
            break;
        case 5:
            printf("�뿩�� å�� ������ �Է��� �ּ���.\n");
            scanf("%s", &bname);

            book* _book = searchNameData(newhead, bname);
            _book->check = TRUE;
            printf("å�� �뿩 �Ǿ����ϴ�.\n");
            break;

        case 6:
            printf("�ݳ��� å�� ������ �Է��� �ּ���\n");
            scanf("%s", &bname);

            book* _book = searchNameData(newhead, bname);
            _book->check = FALSE;
            printf("å�ݳ��� �Ϸ�Ǿ����ϴ�.\n");
            break;
        case 0: return 0;


        default:
            printf("�߸� �Է��Ͽ����ϴ�.\n");
            break;
        }
    }
}