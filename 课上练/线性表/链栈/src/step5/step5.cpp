#include "../seqlist.h"

int main(void)
{
     int m ,x;
      PLinkStack head = createNullStack_link();
     scanf("%d",&m);
     for(int i=0;i<m;i++)
     {
        scanf("%d",&x);
        push_link(head,x);  
      }
 
       printf("%d ",top_link(head));
     
}