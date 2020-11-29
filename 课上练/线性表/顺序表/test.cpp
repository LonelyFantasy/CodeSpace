#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct seqList
{                      //有3个数据成员
    int MAXNUM;        //用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM
    int curNum;        //用于存放顺序线性表中数据元素的个数  整型  curNum
    DataType *element; //用于存放顺序线性表数据元素的连续空间的起始地址
};
typedef struct seqList *PseqList;
//测试输入：6 12 34 56 3 4 12 3 12
int deletePos_seq(PseqList L, int pos)
{ //在顺序表L中删除与下标pos处的数据元素，若pos非法，则返回-1；否则返回1
    int i;
    if (pos < 0 || pos > L->curNum - 1) //非法检查
        return -1;
    else if (pos == L->curNum - 1)
    {
        L->curNum = L->curNum - 1;
        return 1;
    }
    for (i = pos; i < L->curNum - 1; i++)
    {
        L->element[i] = L->element[i + 1];
    }
    L->curNum = L->curNum - 1;
    return 1;
}

int delete_seq(PseqList L, int x)
{ //在顺序表L中删除与参数x值相同的数据元素，返回删除数据元素的个数
    //可以使用之前已完成的操作
    int num = 0;
    for (int i = 0; i < L->curNum; i++)
    {
        if (L->element[i] == x)
            num = num + deletePos_seq(L, i);
    }
    return num;
}

void printList_seq(PseqList L)
{ //逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    //struct seqList *head;
    //head = L;
    for (int i = 0; i < L->curNum; i++)
    {
        printf("%d ", L->element[i]);
    }
}

void replace_seq(PseqList L, int x, int y)
{ //将顺序表L中值为x的数据元素替换为y
    for (int i = 0; i < L->curNum; i++)
        if (L->element[i] == x)
            L->element[i] = y;
}

void delDuplicate_seq(PseqList L)
{ //移除线性表中的所有重复元素；不要使用额外的数组空间，必须在原地修改输入数组 并在使用 O(1) 额外空间的条件下完成，考虑将线性表最后一个元素与需要删除的元素交换
    int flag = 0, temp;
    for (int i = 0; i < L->curNum; i++)
        for (int j = i; j < L->curNum; j++)
        {
            if (L->element[i] == L->element[j] && j != i)
            {
                temp = delete_seq(L, L->element[i]);
                //temp = delete_seq(L, L->element[i]);
            }
            if (L->element[i] == L->element[j] && j != i)
            {
                temp = delete_seq(L, L->element[i]);
                //temp = delete_seq(L, L->element[i]);
            }
        }
}
//测试输入：6 12 4 3 3 3 3 3 12
//测试输入：5 1 5 -1 5 9 5 1
int main()
{

    int i, temp1, temp2, flag1, flag2;
    struct seqList *palist;
    palist = (struct seqList *)malloc(sizeof(struct seqList));
    scanf("%d", &palist->curNum); //
    palist->MAXNUM = 10;
    palist->element = (DataType *)malloc(sizeof(DataType) * palist->curNum);
    for (i = 0; i < palist->curNum; i++)
        scanf("%d", &palist->element[i]); //
    scanf("%d", &flag1);
    scanf("%d", &flag2);
    temp1 = deletePos_seq(palist, flag1);
    printList_seq(palist);
    putchar('\n');
    temp2 = delete_seq(palist, flag2);
    printList_seq(palist);
    printf("\n%d\n%d\n", temp1, temp2);
    delDuplicate_seq(palist);
    printList_seq(palist);
}
