#include "myList.h"
struct Node {
    int element;
    PtrToNode next;
};

int IsEmpty(List L)
{
    return L->next == NULL;
}

int IsLast(Position p, List L)
{
    return p->next == NULL;
}

Position Find(int x, List L)
{
    Position p = L->next;
    while (p && p->element != x) {
        p = p->next;
    }
    return p;
}

Position FindPrevious(int x, List L)
{
    Position p = L;
    while (p->next != NULL && p->next->element != x) {
        p = p->next;
    }
    return p;
}

void Insert(int x, List L, Position p)
{
    Position temp = NULL;
    temp = (Position)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("malloc fail");
    }
    temp->element = x;
    temp->next = p->next;
    p->next = temp;
}

void Delete(int x, List L)
{
    Position temp;
    Position p = FindPrevious(x, L);
    if (IsLast(p, L)) {
        return;
    }
    temp = p->next;
    p->next = temp->next;
    free(temp);
}

void DeleteList(List L)
{
    Position p = L->next;
    Position temp = NULL;
    L->next = NULL;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->next;
}

List MakeEmpty(List L)
{
    DeleteList(L);
    return L;
}

void PrintList(List L)
{
    Position p = L->next;
    while (p) {
        printf("%d->", p->element);
        p = p->next;
    }
    printf("NULL\n");
}

int main(void)
{
    struct Node *header = malloc(sizeof(struct Node));
    header->next = NULL;
    List L = header;
    Insert(10, L, L);
    Insert(20, L, L);
    Insert(30, L, L);

    PrintList(L);
    return 0;
}