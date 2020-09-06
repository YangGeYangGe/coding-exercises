/*
https://leetcode-cn.com/problems/sorted-merge-lcci/submissions/
插入后直接qsort排序
*/

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i;
    for (i = 0; i < n; i++) {
        A[ASize - 1 - i] = B[i];
    }
    qsort(A, ASize, sizeof(int), cmpfunc);
}