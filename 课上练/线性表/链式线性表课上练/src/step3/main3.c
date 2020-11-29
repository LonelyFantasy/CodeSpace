#include "../list.h"

int main(void)
{
    struct node *pllist = mycreateList();
    int num;
    int data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        myinsertTail(pllist, data);
    }
    reverseList_link(pllist);
    myprintList(pllist);
}
