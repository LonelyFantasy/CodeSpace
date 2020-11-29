#include "../seqlist.h"

int main(void)
{
   int m;
   PLinkStack head = createNullStack_link();
   if(head == NULL)
       printf("fail to create");
    else
       printf("success to create a stack"); 
    destroystack_link(head);   
}