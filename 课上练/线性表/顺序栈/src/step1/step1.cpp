#include "../seqlist.h"

int main(void)
{
    int m;
    scanf("%d", &m);
    PseqStack head = createNullStack_seq(m);
    if (head == NULL)
        printf("fail to create");
    else
        printf("success to create a stack of %d elements,current top %d", m, head->top);
    destroystack_seq(head);
}