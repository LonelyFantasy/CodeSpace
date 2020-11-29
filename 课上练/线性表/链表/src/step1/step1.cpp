#include "linklist.h"
/*Only Read*/
int main()
{
  struct node *head = createRlist();
  int num, data;
  scanf("%d", &num);
  for (int i = 0; i < num; i++)
  {
    scanf("%d", &data);
    insertOrder(head, data);
  }
  printRlist(head);
  scanf("%d", &data);
  printf("\n%d ", deleteData(head, data));
  printRlist(head);
  printf("\n%d ", destroyRlist(head));

  return 1;
}