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

void merge(SortObject *r, SortObject *r1, int low, int m, int high)
{
    int i = low, j = m + 1, k = low;
    while (i < m && j < high)
    {
        if (r->data[i] < r->data[j])
            r1->data[k++] = r->data[i++];
        else
            r1->data[k++] = r->data[j++];
    }
    while (i <= m)
        r1->data[k++] = r->data[i++];
    while (j <= high)
        r1->data[k++] = r->data[j++];
}
void mergePass(SortObject *r, SortObject *r1, int n, int length) //length为当前归并排序下有序子文件的长度
{
    int i = 0, j;
    while (i + 2 * length - 1 < n) //判断排序是否到头
    {
        merge(r, r1, i + length - 1, i + 2, length - 1); //调用子块排序
        i += 2 * length;                                 //往后继续划分
    }
    if (i + length - 1 < n - 1)                 //若剩下的两个子块中长度不一，且有一个子块小于规定长度length
        merge(r, r1, i, i + length - 1, n - 1); //进行自我排序
    else                                        //仅剩下一段未排序的，直接复制到r1中
        for (j = i; j < n; j++)
            r1->data[j] = r->data[j];
}

void mergeSort(SortObject *source)
{
    int length = 1;
    SortObject temp[36278];
    while (length < source->NUM)
    {
        //第一趟归并，用temp暂存
        mergePass(source, temp, source->NUM, length);
        length *= 2;
        //排完后进行第二趟排序，放回原结构中
        mergePass(temp, source, source->NUM, length);
        length *= 2;
    }
}