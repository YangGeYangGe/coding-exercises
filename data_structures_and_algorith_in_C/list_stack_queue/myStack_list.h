#ifndef _STACK_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(int x, Stack s);
int Top(Stack s);
void Pop(Stack s);
#endif