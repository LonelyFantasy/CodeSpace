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
        push_seq(head, x);
    }
    while (isNullStack_seq(head) == 0)
        printf("%d ", pop_seq(head));
    destroystack_seq(head);
}