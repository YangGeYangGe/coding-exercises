#include "myStack_array.h"
#include "stdlib.h"
#include "stdio.h"
#define MAX_ELEMENTS    20
#define EMPTY_FLAG      -1
struct StackRecord
{
    int capacity;
    int topOfStack;
    int *array;
};

Stack CreateStack(void)
{
    Stack s = malloc(sizeof(struct StackRecord));
    if (s == NULL) {
        printf("malloc err\n");
        return NULL;
    }
    s->array = malloc(sizeof(int) * MAX_ELEMENTS);
    if (s->array == NULL) {
        free(s);
        printf("array malloc err\n");
        return NULL;
    }
    s->capacity = MAX_ELEMENTS;
    s->topOfStack = EMPTY_FLAG;
    return s;
}

int IsEmpty(Stack s)
{
    return s->topOfStack == EMPTY_FLAG;
}

void MakeEmpty(Stack s)
{
    s->topOfStack = EMPTY_FLAG;
}

void DisposeStack(Stack s)
{
    if (s == NULL) {
        return;
    }
    free(s->array);
    free(s);
}

int Top(Stack s)
{
    if (IsEmpty(s)) {
        printf("empty!!\n");
        return -1;
    }
    return s->array[s->topOfStack];
}

int IsFull(Stack s)
{
    return s->topOfStack == MAX_ELEMENTS - 1;
}

void Push(int x, Stack s)
{
    if (IsFull(s)) {
        return;
    }
    s->array[++s->topOfStack] = x; 
}

void Pop(Stack s)
{
    if (IsEmpty(s)) {
        return;
    }
    s->topOfStack--;
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