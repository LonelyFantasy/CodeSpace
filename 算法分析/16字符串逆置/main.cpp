#include <iostream>
#include <string.h>
using namespace std;
typedef char DataType;
struct seqList
{                      //有3个数据成员
    int MAXNUM;        //用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM
    int curNum;        //用于存放顺序线性表中数据元素的个数  整型  curNum
    DataType *element; //用于存放顺序线性表数据元素的连续空间的起始地址
};
typedef struct seqList *PseqList;
PseqList createNullList_seq(int m)
{
    PseqList palist;
    palist = (struct seqList *)malloc(sizeof(struct seqList));
    palist->curNum = 0;
    palist->MAXNUM = m;
    palist->element = (DataType *)malloc(sizeof(DataType) * m);
    if (m <= 0)
        return NULL;
    else
        return palist;
}
void destroyList_seq(PseqList L)
{
    if (L)
    {
        free(L->element);
        free(L);
    }
}
void printList_seq(PseqList L)
{
    for (int i = 0; i < L->curNum; i++)
        printf("%c ", L->element[i]);
}

void trans(PseqList L, int m)
{
    int i;
    char temp;
    for (i = 0; i < m / 2; i++)
    {
        temp = L->element[i];
        L->element[i] = L->element[m - 1 - i];
        L->element[m - 1 - i] = temp;
    }
}
int main()
{
    int m;
    while (1)
    {
        scanf("%d", &m);
        getchar();
        PseqList head;
        head = createNullList_seq(m + 1); //+1腾出'\0'位
        if (head == NULL)
            return 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%c", &head->element[i]);
            head->curNum++;
        }
        if (head->curNum > m)
        {
            printf("Out of space!");
            return 0;
        }
        printf("逆置字符串:");
        trans(head, m);
        printList_seq(head);
        putchar('\n');
        destroyList_seq(head);
    }
    return 0;
}