#include "../seqlist.h"

int main(void)
{
   int m;
   scanf("%d",&m);
   PseqQueue head = createNullQueue_seq(m);
   if(head == NULL)
       printf("fail to create");
    else
       printf("success to create a queue of %d elements,current front %d",m,head->front); 
    destroyQueue_seq(head);   
}