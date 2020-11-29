#include "../seqlist.h"

int main(void)
{
    int m, x;
    scanf("%d", &m);
    PseqStack head = createNullStack_seq(m);

    printf("%d", isNullStack_seq(head));
    destroystack_seq(head);
}