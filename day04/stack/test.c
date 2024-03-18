/*연결리스트로 구현*/
#include <stdio.h>

#define STACK_SZ 10
typedef struct STACK
{
    int buf[STACK_SZ]; // 데이터를 저장 할 수 있는것, c언어에서는 구조체 내애서 배열의 크기를 비워둘수 없다.
    int top;
}stack;

void push(stack*, int value);
int pop(stack*);

void main()
{
    stack s; // 스택 구조체를 생성
    s.top = -1;
    push(&s, 10);
    push(&s, 20);            // &사용하는 이유는 해당 함수에 스택구조체의 주소를 전달하기 위해서
    //printf("%d\n", pop(&s));
    //printf("%d\n", pop(&s));

}
void push(stack* pstk, int value)
{
    //stack* newstack = (stack*)malloc(sizeof(stakc));
    if (pstk->top < STACK_SZ - 1)         // 이거사용하는 이유 ->예외처리때문.
    {
        pstk->top++;
        pstk->buf[pstk->top] = value;
        printf("%d 이 입력되었습니다.\n", value);
    }
}

/*
int pop(stack* pstk)
{
    if (pstk->top < 0)
    {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    int del = pstk->buf[pstk->top];
    pstk->top--;
    return del;
}

*/
