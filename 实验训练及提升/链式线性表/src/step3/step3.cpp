#include "linklist.h"
int main(void)
{
    struct node *A, *B, *C;
    int i, j;
    A = mycreateList();
    B = mycreateList();
    scanf("%d", &i);
    genNumber(A, i);
    scanf("%d", &j);
    genNumber(B, j);
    C = addNumber(A, B);
    myprintList(C);
    return 1;
}
