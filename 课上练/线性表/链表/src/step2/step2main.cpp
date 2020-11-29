#include "doublelist.h"

int main()
{   
  struct Hnode *head = createDlist();
  int num , data;
  scanf("%d",&num);
  for(int i=0;i<num;i++)
  {
     scanf("%d",&data);
     insertDlist(head, data);
  }
  printDlist(head);
  scanf("%d",&data);
  printf("\n%d ",deleteData(head,data));
  printDlist(head);
  getchar();
  printf("\n%d ", destroyDlist(head));

  return 1;
}