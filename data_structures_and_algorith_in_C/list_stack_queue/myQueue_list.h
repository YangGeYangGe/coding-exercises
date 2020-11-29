#ifndef _QUEUE_H

struct Node
{
    int element;
    struct Node *next;
};
typedef struct Node *PtrToNode;
typedef struct linkqueue{
    PtrToNode  front; 
    PtrToNode  rear;
} rQueue, *Queue;

int IsEmpty(Queue q);
Queue CreateQueue(void);
void DisposeQueue(Queue q);

void MakeEmpty(Queue q);
void Enqueue(int x, Queue q);
int Front(Queue q);
void Dequeue(Queue q);

#endif