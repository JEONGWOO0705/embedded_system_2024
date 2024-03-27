/*
Filr : id.c
Created : 24-03-27
author : Ȳ����
*/




#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ���� ����
char bname[BUF_SIZE];
char bauthor[BUF_SIZE];
char bpublisher[BUF_SIZE];
int bId;
int bprice;
int bpage;



char msg[BUF_SIZE];
char BUF[BUF_SIZE];
char ID[BUF_SIZE];
char PASSWORD[BUF_SIZE];

char AddreddBook[BUF_SIZE];
char EnterID[BUF_SIZE];
char EnterPASSWORD[BUF_SIZE];
char IDmsg[100];
char Passwordmsg[100];

//���� �ε� �ڵ�
void loadFileout(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error_handling("fopen() error\n");
    }
    while (fgets(BUF, sizeof(BUF), file) != NULL) {
        printf("file data: %s", BUF);
    }
    fclose(file);
}

void loadFilesave(const char* filename, char value[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error_handling("fopen() error\n");
    }
    fgets(value, BUF_SIZE, file);
    fclose(file);
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void makeFile(const char* filename, const char* value) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "������ �� �� �����ϴ�.\n");
        exit(1);
    }
    fprintf(fp, "%s", value);
    fclose(fp);

}


headNode* createHeadNode() {
    headNode* newHead = malloc(sizeof(headNode));
    if (newHead == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    newHead->head = NULL;
    return newHead;
}
// ��� ������ ��� �ڵ� 
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
    if (curr == NULL) {
        printf("��ȸ�Ǵ� å�� �����ϴ�.\n");
    }
}   // ��� ������ ��� �ڵ�
// ���� ������ ��� �ڵ�
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

// ������ �߰� �ڵ�
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
// ������ �߰� �ڵ�(����)
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
// ������ �Է� �ڵ�
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
        while (getchar() != '\n'); // �Է� ���� a����
    }
}

// å �������� ������ ã��
book* searchNameData(headNode* pnode, const char* _name) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->name, _name) == 0) {
            return search; // �˻��� å�� ã���� �ش� ��带 ��ȯ
        }
        search = search->next;
    }
    printf("å�� �˻��� �� �����ϴ�.\n");
    return NULL;

}

// å ���ǻ�� ������ ã��
book* searchPublisherData(headNode* pnode, const char* _pub) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->publisher, _pub) == 0) {
            return search; // �˻��� å�� ã���� �ش� ��带 ��ȯ
        }
        search = search->next;
    }
    printf("å�� �˻��� �� �����ϴ�.\n");
    return NULL;
}
// å �۰��� ������ ã��
book* searchAuthorData(headNode* pnode, const char* _author) {
    book* search = pnode->head;
    while (search != NULL) {
        if (strcmp(search->author, _author) == 0) {
            return search; // �˻��� å�� ã���� �ش� ��带 ��ȯ
        }
        search = search->next;
    }
    printf("å�� �˻��� �� �����ϴ�.\n");
    return NULL; // �˻��� å�� ���� ��� NULL ��ȯ
}
//��ü ������ ���� �ڵ�
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
// ���� ������ ���� �ڵ�
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

int menu(void) {
    int choice;
    book books[BUF_SIZE];
    books->check = FALSE;

    int numBooks = 0;
    headNode* newhead = createHeadNode();

    loadFilesave("id.txt", ID);
    loadFilesave("password.txt", PASSWORD);
    printf("������ ���α׷� ID�� PASSWORD�� �Է��� �ּ���\n");


    printf("���̵� �Է��ϼ��� : \n");
    scanf("%s", EnterID);

    printf("��й�ȣ�� �Է��ϼ��� : \n");
    scanf("%s", EnterPASSWORD);

    while (TRUE) {
        if (strcmp(ID, EnterID) == 0 && strcmp(PASSWORD, EnterPASSWORD) == 0) {
            printf("�α��� ���� �Ͽ����ϴ�.\n");
            while (1) {
                printf("***** �޴� *****\n");
                printf("1. ���� ���\n");
                printf("2. ���� �˻�\n");
                printf("3. ���� ����\n");
                printf("4. ���� ���\n");
                printf("5. �뿩 üũ\n");
                printf("6. �ݳ� üũ\n");
                printf("7. ���̵� ����\n");
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
                    printf("�˻��� ī�װ����� ���Ͻÿ� \n");
                    printf("1. å ����\n");
                    printf("2. ���ǻ�\n");
                    printf("3. ����\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("å�� ������ �Է��� �ּ��� : \n");
                        scanf("%99s", bname);
                        book* found = searchNameData(newhead, bname);
                        if (found != NULL) {
                            printBookInfo(found);
                        }
                    }
                    else if (choice == 2) {
                        printf("å�� ���ǻ縦 �Է��� �ּ��� : \n");
                        scanf("%99s", bpublisher);
                        book* found = searchPublisherData(newhead, bpublisher);
                        if (found != NULL) {
                            printBookInfo(found);
                        }
                    }
                    else if (choice == 3) {
                        printf("å�� ���� �Է��� �ּ��� : \n");
                        scanf("%99s", bauthor);
                        book* found = searchAuthorData(newhead, bauthor);
                        if (found != NULL) {
                            printBookInfo(found);
                        }
                    }
                    break;

                case 3:
                    printf("������ å�� ������ �Է��ϼ���. \n");
                    scanf("%s", bname);
                    book* del = searchNameData(newhead, bname);
                    if (del != NULL) {
                        selectFreeNode(newhead, bname);
                        printf("å�� �����Ǿ����ϴ�.\n");
                        break;
                    }
                    else {
                        break;
                    }

                case 4:
                    printf("��ü ������ ����ϰڽ��ϴ�.\n");
                    ShowAllNode(newhead);
                    break;
                case 5:
                    printf("�뿩�� å�� ������ �Է��� �ּ���.\n");
                    scanf("%s", bname);

                    book* _book = searchNameData(newhead, bname);

                    if (_book != NULL) {
                        if (_book->check == FALSE) {
                            _book->check = TRUE;
                            printf("å�� �뿩 �Ǿ����ϴ�.\n");
                        }
                        else if (_book->check == TRUE) {
                            printf("�ش� å�� �̹� �뿩 �Ǿ����ϴ�.\n");

                        }
                        break;
                    }

                    else {
                        break;
                    }


                case 6:
                    printf("�ݳ��� å�� ������ �Է��� �ּ���\n");
                    scanf("%s", bname);

                    book* k = searchNameData(newhead, bname);


                    if (k != NULL) {
                        if (k->check == TRUE) {
                            k->check = FALSE;
                            printf("å�� �ݳ� �Ǿ����ϴ�.\n");
                        }
                        else if (k->check == FALSE) {
                            printf("�ش� å�� �̹� �ݳ� �Ǿ����ϴ�.\n");
                        }
                        break;
                    }
                    else {
                        break;
                    }

                case 7:
                    printf("1. ������ ���̵� ����\n");
                    printf("2. ����\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("������ ID�� �Է��ϼ���: ");
                        scanf("%s", ID);

                        printf("������ PASSWORD�� �Է��ϼ���: ");
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
                    printf("�߸� �Է��Ͽ����ϴ�.\n");
                    break;
                }
            }
        }
        else {
            printf("��� ��ȣ�� Ʋ���ϴ�.\n");
            printf("\n");
            printf("�����Ͻðڽ��ϱ�? \n");
            printf("1���� ������ ����˴ϴ�. \n");
            printf("�ƴ϶�� �ٸ� ��ȣ�� �Է��� �ּ���.\n");
            scanf("%d", &choice);
            if (choice == 1) {
                return 0;
            }
            else {
                printf("������ ���α׷� ID�� PASSWORD�� �Է��� �ּ���\n");
                printf("���̵� �Է��ϼ��� : \n");
                scanf("%s", EnterID);

                printf("��й�ȣ�� �Է��ϼ��� : \n");
                scanf("%s", EnterPASSWORD);
            }

        }
    }


    return 0;
}