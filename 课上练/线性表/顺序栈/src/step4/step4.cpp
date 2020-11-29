#include "../seqlist.h"

int main(void)
{
    int m, x;
    scanf("%d", &m);
    PseqStack head = createNullStack_seq(m);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        printf("%d ", push_seq(head, x));
    }
    destroystack_seq(head);
}