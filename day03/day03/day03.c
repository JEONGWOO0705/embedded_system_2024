#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
}node;

typedef struct {
    node* head;
}headNode;

headNode* createHeadNode(void) {
    headNode* newHead = malloc(sizeof(headNode));
    newHead->head = NULL;
    return  newHead;
}

void ShowNode(headNode* pnode) {
    node* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        printf("%d번째 데이터 값 : %d\n", i, curr->data);
        curr = curr->next;
    }
}

void pre_addNode(headNode* pnode, int _data) {
    node* newnode = malloc(sizeof(node));

    newnode->next = pnode->head;
    pnode->head = newnode;
    newnode->data = _data;
    printf("노드가 생성되었습니다\n");
}

void rearNode(headNode* pnode, int _data) {
    node* newnode = malloc(sizeof(node));
    newnode->data = _data;
    newnode->next = NULL;
    node* curr = pnode->head; // pnode(head)에 next값이 저장되있는 것이 아니라
    // pnode->head 에 저장되어 있다
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newnode;
}

void allFreeNode(headNode* pnode) {
    node* curr = pnode->head;
    while (curr != NULL) {
        node* dn = curr;
        curr = curr->next;
        printf("데이터 삭제\n");
        free(dn);
    }
    pnode->head->next = NULL;
    printf("head -> next : %d,  head->data: %d \n", pnode->head->next, curr);
    free(pnode);
}

void main() {

    //  node*head = (node*)malloc(sizeof(node));
     //  head->next=NULL
    headNode* newhead = createHeadNode();
    pre_addNode(newhead, 10);
    pre_addNode(newhead, 20);
    pre_addNode(newhead, 30);
    rearNode(newhead, 11);
    rearNode(newhead, 22);
    rearNode(newhead, 100);
    node* curr = newhead->head;

    while (curr != NULL) {
        printf("데이터는 %d\n", curr->data);
        curr = curr->next;
    }
    printf("-------함수 호출----------\n");
    ShowNode(newhead);
    allFreeNode(newhead);
}

