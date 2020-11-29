#ifndef _LINKSET_H_
#define _LINKSET_H_
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

struct node
{
  DataType element;
  struct node *next;
};
typedef struct node *SET;
void insert(DataType datax, SET set);

/*
  函数名： InitSet
  函数功能：根据参数num，初始化集合
  函数参数：集合元素的个数 
  返回值：集合头指针
*/
SET InitSet(int num)
{
  SET p;
  p = (struct node *)malloc(sizeof(struct node));
  p->next = NULL;
  p->element = num;
  int temp;
  for (int i = 0; i < num; i++)
  {
    scanf("%d", &temp);
    insert(temp, p); //调用insert函数，将输入数据插入集合
  }
  return p;
}

/*
  函数名： find
  函数功能：在集合中查找值为datax的成员 
  函数参数：datax:待查找的值 ； set：集合的头结点 
  返回值：找到值为datax的成员返回1，否则返回0 
  时间复杂度：O(set->element)
*/
int find(DataType datax, SET set)
{
  //请在此处填写代码，在set集合中查找值为datax的成员，若找到返回1，否则返回0
  /**********  Begin  **********/
  SET current = set->next;
  while (current != NULL)
  {
    if (current->element == datax)
      return 1;
    current = current->next;
  }
  return 0;
  /**********   End   **********/
}

/*
  函数名： insert
  函数功能：在集合set中插入值为datax的成员 ，插入位置在表头 
  函数参数：datax:待插入的值 ； set：集合的头结点 
  返回值：无 
  时间复杂度：O(1)
*/
void insert(DataType datax, SET set)
{
  //请在此处填写代码，将datax插入集合set， 注意因集合元素是无序的，只需将新成员插入表头
  /**********  Begin  **********/
  SET current = (SET)malloc(sizeof(struct node));
  current->element = datax;
  current->next = set->next;
  set->next = current;
  set->element++; //set元素个数+1
  /**********   End   **********/
}

/*
  函数名： copyList
  函数功能：将集合setA复制生成集合setB 
  函数参数：setA 、setB的头结点 
  返回值：无 
*/
void copySet(SET setA, SET setB)
{
  //请在此处填写代码，实现将集合setA的成员复制到集合setB的功能
  /**********  Begin  **********/
  SET current = setA->next;
  while (current != NULL)
  {
    insert(current->element, setB);
    current = current->next;
  }
  /**********   End   **********/
}

/*
  函数名： printSet
  函数功能：输出集合的元素，以空格作为元素之间分界符 
  函数参数：set的头结点 
  返回值：无 
*/
void printSet(SET set)
{
  //请在此处填写代码，实现输出集合元素的功能，元素之间以空格为分界符
  /**********  Begin  **********/
  SET current = set->next;
  while (current->next != NULL)
  {
    printf("%d ", current->element);
    current = current->next;
  }
  printf("%d ", current->element);
  /**********  End  **********/
}

/*
  函数名： setUnion
  函数功能：求两个集合setA 和 setB的并集 
  函数参数：setA和setB的头结点 
  返回值：并集集合的头结点 
*/
SET setUnion(SET setA, SET setB)
{
  //请在此处填写代码，可直接使用上面已经实现的各操作
  /**********  Begin  **********/

  SET cpyA = (SET)malloc(sizeof(struct node)), B = setB->next;
  copySet(setA, cpyA);
  while (B != NULL)
  {
    if (find(B->element, setA) == 0)
      insert(B->element, cpyA);
    B = B->next;
  }
  return cpyA;
  /**********  End  **********/
}

/*
  函数名： setIntersect
  函数功能：求两个集合setA 和 setB的交集 
  函数参数：setA和setB的头结点 
  返回值：交集集合的头结点 
*/
SET setIntersect(SET setA, SET setB)
{
  //请在此处填写代码，可直接使用上面已经实现的各操作
  /**********  Begin  **********/
  SET setC = (SET)malloc(sizeof(struct node)), curA = setA->next; //输出集合C，当前集合A
  while (curA != NULL)
  {
    if (find(curA->element, setB) == 1)
      insert(curA->element, setC);
    curA = curA->next;
  }
  return setC;
  /**********  End  **********/
}

/*
  函数名： setExcept
  函数功能：求两个集合setA 和 setB的差 
  函数参数：setA和setB的头结点 
  返回值：结果集合的头结点 
*/
SET setExcept(SET setA, SET setB)
{
  //请在此处填写代码，可直接使用上面已经实现的各操作
  /**********  Begin  **********/
  SET setC = (SET)malloc(sizeof(struct node)), curA = setA->next, curB; //输出集合C
  while (curA != NULL)
  {
    if (find(curA->element, setB) == 0)
      insert(curA->element, setC);
    curA = curA->next;
  }
  return setC;
  /**********  End  **********/
}

void destroySet(SET set)
{
  //释放存储集合的链表空间，表头为set
  SET current;
  while (set != NULL)
  {
    current = set;
    set = set->next;
    free(current);
  }
}

#endif