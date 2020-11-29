#include "../list.h"

 int main(void)
 {
 	 struct node  *pllist = mycreateList() ;
 	 int num ;
	 int data;
     int pos ;
 	 scanf("%d",&num);
 	 for(int i = 0;i < num; i++)
 	   {
 	   	  scanf("%d",&data);
 	   	  myinsertTail(pllist, data);
		}
    scanf("%d",&data); 
	printf("%d",locateAndChange(pllist,data));
 }