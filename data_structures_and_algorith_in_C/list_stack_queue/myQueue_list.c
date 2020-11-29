#include "myQueue_list.h"
#include <stdlib.h>
#include <stdio.h>

Queue CreateQueue(void)
{
    Queue q = malloc(sizeof(rQueue));
    if (q == NULL) {
        printf("err\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int IsEmpty(Queue q)
{
    return q->rear == NULL;
}

void Enqueue(int x, Queue q)
{
    PtrToNode newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("malloc err!\n");
        return;
    }
    newNode->element = x;
    newNode->next = NULL;
    
    // queue is empty, front and rear are both empty
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void Dequeue(Queue q)
{
    if (IsEmpty(q)) {
        printf("is empty\n");
        return;
    }
    PtrToNode temp = q->front;
    if (q->front->next == NULL) {
        free(temp);
        q->front = NULL;
        q->rear = NULL;
        return;
    }
    q->front = q->front->next;
    free(temp);
}

int Front(Queue q)
{
    if (IsEmpty(q)) {
        printf("is empty!\n");
        return -1;
    }
    return q->front->element;
}

void DisposeQueue(Queue q)
{
    PtrToNode temp = NULL;
    while (!IsEmpty(q)) {
        Dequeue(q);
    }
    free(q);
}

int main(void)
{
    Queue s = CreateQueue();
    Enqueue(1, s);
    printf("Front %d\n", Front(s));
    Enqueue(2, s);
    printf("Front %d\n", Front(s));
    Enqueue(3, s);
    printf("Front %d\n", Front(s));
    Enqueue(4, s);
    printf("Front %d\n", Front(s));

    Dequeue(s);
    printf("Front %d\n", Front(s));
    Dequeue(s);
    printf("Front %d\n", Front(s));
    Dequeue(s);
    printf("Front %d\n", Front(s));
    printf("Front %d\n", Front(s));
    Dequeue(s);
    printf("Front %d\n", Front(s));
    return 0;
}