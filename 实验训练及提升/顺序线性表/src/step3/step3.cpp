#include "../seqlist.h"
int main()
{
    int num , data ;
    int pos[2];
    scanf("%d",&num);
    PseqList plist = createNullList_seq(num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&data);
        insertP_tail( plist ,data);
    }
    scanf("%d",&data);
    findPos(plist,data,pos);
    printf("%d %d",pos[0],pos[1]);
}