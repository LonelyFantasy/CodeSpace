#include "../seqlist.h"

int main(void)
{
    int m, x;
    scanf("%d", &m);
    PseqQueue head = createNullQueue_seq(m);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        enQueue_seq(head, x);
    }
    while (isNullQueue_seq(head) == 0)
        printf("%d ", delQueue_seq(head));
    destroyQueue_seq(head);
}