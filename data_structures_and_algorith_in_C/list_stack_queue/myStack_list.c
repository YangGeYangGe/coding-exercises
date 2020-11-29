#include "myStack_list.h"
#include "stdlib.h"
#include "stdio.h"

struct Node {
    int element;
    struct Node *next;
};

int IsEmpty(Stack s)
{
    return s->next == NULL;
}

Stack CreateStack(void)
{
    Stack s = malloc(sizeof(struct Node));
    if (s == NULL) {
        printf("malloc err\n");
        return NULL;
    }
    s->next = NULL;
    return s;
}

void MakeEmpty(Stack s)
{
    if (s == NULL) {
        return;
    }
    while (!IsEmpty(s)) {
        Pop(s);
    }
}

void Pop(Stack s)
{
    PtrToNode p = NULL;
    if (IsEmpty(s)) {
        return;
    }
    p = s->next;
    s->next = s->next->next;
    free(p);
}

int Top(Stack s)
{
    PtrToNode p = NULL;
    if (IsEmpty(s)) {
        printf("err\n");
        return -1;
    }
    return s->next->element; 
}

void Push(int x, Stack s)
{
    PtrToNode temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("malloc err\n");
        return;
    }
    temp->next = s->next;
    s->next = temp;
    temp->element = x;
}

void DisposeStack(Stack s)
{
    MakeEmpty(s);
    free(s);
}

int main(void)
{
    Stack s = CreateStack();
    Push(1, s);
    printf("top %d\n", Top(s));
    Push(2, s);
    printf("top %d\n", Top(s));
    Push(3, s);
    printf("top %d\n", Top(s));
    Push(4, s);
    printf("top %d\n", Top(s));
    return 0;
}
