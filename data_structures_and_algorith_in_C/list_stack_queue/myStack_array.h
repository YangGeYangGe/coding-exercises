#ifndef _STACK_H
struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(int x, Stack s);
int Top(Stack s);
void Pop(Stack s);
int TopAndPop(Stack s);
#endif