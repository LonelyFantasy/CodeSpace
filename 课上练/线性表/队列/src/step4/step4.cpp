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
        printf("%d ", enQueue_seq(head, x));
    }
    destroyQueue_seq(head);
}