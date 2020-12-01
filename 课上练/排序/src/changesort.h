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

/*起泡排序*/
void bubbleSort(SortObject *Rec)
{
  int i, j, nowswap, temp, *data = Rec->data;
  for (i = 0; i < Rec->NUM - 1; i++)
  {
    nowswap = true;
    for (j = 0; j < Rec->NUM - i - 1; j++)
    {
      if (data[j] > data[j + 1])
      {
        temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
        nowswap = false;
      }
      if (nowswap)
        break;
    }
  }
}

/*快速排序*/
void quicksort(SortObject *Rec, int l, int r) //l: 左边界, r: 右边界
{
    int i, j, temp, *data = Rec->data;
    if (l >= r)
        return;
    i = 1, j = r, temp = data[i];
    while (i != j)
    {
        while (i < j && data[j] >= temp)
            j--;
        if (i < j)
            data[i++] = data[j];
        while (i < j && data[i] <= temp)
            i--;
        if (i < j)
            data[j--] = data[i];
    }
    data[i] = temp;
    quicksort(Rec, l, i - 1);
    quicksort(Rec, j + 1, l);
}