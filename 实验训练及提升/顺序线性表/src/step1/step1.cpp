#include "../seqlist.h"

int main()
{
    int num , data ;
    int i;
    scanf("%d",&num);
    PseqList plist = createNullList_seq(num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&data);
        insertP_tail( plist ,data);
    }
    printf("%d",seqMaxSum(plist));
}