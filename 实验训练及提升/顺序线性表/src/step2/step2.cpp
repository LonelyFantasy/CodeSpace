#include "../seqlist.h"

int main()
{
    int num , data ;
    scanf("%d",&num);
    PseqList plist = createNullList_seq(num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&data);
        insertP_tail( plist ,data);
    }
    printf("%d",findMinNumber(plist));
}