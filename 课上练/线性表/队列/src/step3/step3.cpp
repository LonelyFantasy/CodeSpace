#include "../seqlist.h"

int main(void)
{
    int m, x;
    scanf("%d", &m);
    PseqQueue head = createNullQueue_seq(m);
    printf("%d", isFullQueue_seq(head));
    destroyQueue_seq(head);
}