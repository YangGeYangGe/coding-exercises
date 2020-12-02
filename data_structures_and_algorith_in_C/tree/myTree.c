#include <stdlib.h>
#include <stdio.h>
#include "mytree.h"
struct TreeNode
{
    int element;
    SearchTree left;
    SearchTree right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL) {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(int x, SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }
    if (x < T->element) {
        return Find(x, T->left);
    } else if (x > T->element) {
        return Find(x, T->right);
    }
    return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }
    if (T->left == NULL) {
        return T;
    }
    return FindMin(T->left);
}

SearchTree Insert(int x, SearchTree T)
{
    // found the position to insert
    if (T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL) {
            printf("malloc err\n");
            return NULL;
        }
        T->element = x;
        T->left = T->right = NULL;
    } else if (x < T->element) {
        T->left = Insert(x, T->left);
    } else if (x > T->element) {
        T->right = Insert(x, T->right);
    }
    return T;
}

SearchTree Delete(int x, SearchTree T)
{
    Position tempCell;
    if (T == NULL) {
        return NULL;
    }
    if (x < T->element) {
        T->left = Delete(x, T->left);
    } else if (x > T->element) {
        T->right = Delete(x, T->right);
    } else {
        if (T->left && T->right) {
            tempCell = FindMin(T->right);
            T->element = tempCell->element;
            T->right = Delete(T->element, T->right);
        } else {
            tempCell = T;
            if (T->left == NULL) {
                T = T->right;
            } else if (T->right == NULL) {
                T = T->left;
            }
            free(tempCell);
        }
    }
    return T;
}

int main(void)
{
    return 0;
}