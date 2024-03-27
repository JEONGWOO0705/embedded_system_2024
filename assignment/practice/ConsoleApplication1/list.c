/*
Filr : list.c
Created : 24-03-27
author : Ȳ����
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

