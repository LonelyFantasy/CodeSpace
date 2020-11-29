#include "../seqlist.h"

int main(void)
{
     int m ,x;
     scanf("%d",&m);
     PLinkStack head = createNullStack_link(m);
     printf("%d",isNullStack_link(head));
       
}