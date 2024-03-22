#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void ShowNode(headNode* pnode) {
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
        }

    }