#include <stdio.h>
#include <stdlib.h>

/*数据结构定义*/
typedef int DataType;
typedef struct
{
  DataType *data; //用于存放待排序关键字的起始地址
  int NUM;        //待排序关键字的个数
} SortObject;

typedef struct node //用于表插入排序的数据结构
{
  DataType info;
  struct node *next;
} linkObject;

//输出顺序表
void print(SortObject *p)
{
  for (int i = 0; i < p->NUM; i++)
    printf("%d ", p->data[i]);
  printf("\n");
}

//输出链表
void printLink(linkObject *Head)
{
  linkObject *p = Head->next;
  while (p)
  {
    printf("%d ", p->info);
    p = p->next;
  }
  printf("\n");
}

/*第一关
此处请填写代码实现递增序进行直接插入排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况*/
void insertSort(SortObject *Rec)
{
  SortObject *cur = Rec;
  int i, j;
  int temp;
  for (i = 1; i < Rec->NUM; ++i)
  {
    temp = cur->data[i];
    for (j = i - 1; cur->data[j] > temp && j >= 0; j--)
      cur->data[j + 1] = cur->data[j];
    if (j != i - 1)
      cur->data[j + 1] = temp;
    print(Rec);
  }
}

/*第二关
  此处请填写代码实现递增序进行二分插入排序,
  实质是在已经有序的表中采用二分法查找插入位置
  要求每趟排序后 调用print函数，输出关键字的排列情况*/
void binInsertSort(SortObject *Rec)
{
  int head, middile, tail, i, j, temp;
  int *cur_data = Rec->data;
  for (i = 1; i < Rec->NUM; i++)
  {
    temp = cur_data[i];
    head = 0;
    tail = i - 1;
    while (head <= tail)
    {
      middile = (head + tail) / 2;
      if (temp < cur_data[middile])
        tail = middile - 1;
      else
        head = middile + 1;
    }
    for (j = i - 1; j >= head; j--)
      cur_data[j + 1] = cur_data[j];
    if (head != i)
      cur_data[head] = temp;
    print(Rec);
  }
}

/* 第四关
此处请填写代码实现递增序进行shell排序,
  
  要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void shellSort(SortObject *Rec, int d)
{
  int i, j, inc, temp;
  int *cur_data = Rec->data;
  for (inc = d; inc > 0; inc /= 2)
  {
    for (i = inc; i < Rec->NUM; i++)
    {
      temp = cur_data[i];
      for (j = i - inc; j >= 0 && temp < cur_data[j]; j -= inc)
        cur_data[j + inc] = cur_data[j];
      cur_data[j + inc] = temp;
    }
    print(Rec);
  }
}

/*第三关
此处请填写代码实现递增序进行表插入排序,
  返回值是关键字比较次数
  Head是表头结点，不存放数据，info是待插入数据
  要求每趟排序后 调用printLink函数，输出关键字的排列情况
  */
void listSort(linkObject *plist)
{
  linkObject *now, *pre, *p, *q, *head;
  head = plist;
  pre = head->next;
  if (pre == NULL)
    return;
  now = pre->next;
  if (now == NULL)
    return;
  while (now != NULL)
  {
    q = head;
    p = head->next;
    while (p != now && p->info <= now->info)
    {
      q = p;
      p = p->next;
    }
    if (p == now)
    {
      pre = pre->next;
      now = pre->next;
      printLink(plist);
      continue;
    }
    pre->next = now->next;
    q->next = now;
    now->next = p;
    now = pre->next;
    printLink(plist);
  }
}
