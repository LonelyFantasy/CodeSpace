 #include "../list.h"

int main(void)
{
	struct node *L = mycreateList();
    int a[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++)
        if(i%2) myinsertTail(L,a[i]);
        else  myinsertHead(L,a[i]);
	myprintList(L);
 } 