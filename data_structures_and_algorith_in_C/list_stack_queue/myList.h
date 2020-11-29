#ifndef _List_H
#include <stdlib.h>
#include <stdio.h>

struct Node;
typedef struct Node *PtrToNode;

// List has a header/dummpy node pointing to NULL or a node
typedef PtrToNode List;
typedef PtrToNode Position;


List MakeEmpty(List L);

/* return TRUE if L is empty */
int IsEmpty(List L);

/* Return true if P is the last position in list L */
int IsLast(Position P, List L);

/* Return Position of X in L; NULL if not found */
Position Find(int x, List L);

void Delete(int x, List L);

Position FindPrevious(int x, List L);

/* inster after legal position p */
void Insert(int x, List L, Position p);

void DeleteList(List L);

Position Header(List L);

Position First(List L);
#endif