#include "../seqlist.h"

int main(void)
{
     int m ,x;
     scanf("%d",&m);
     PLinkStack head = createNullStack_link();
    for(int i=0;i<m;i++)
     {
        scanf("%d",&x);
        printf("%d ",push_link(head,x));  
      }
   
    
}