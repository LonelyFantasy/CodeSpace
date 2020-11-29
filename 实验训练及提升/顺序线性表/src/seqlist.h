#include <stdio.h>
#include <stdlib.h>

/*此处是顺序线性表数据结构定义*/
typedef int DataType;
struct seqList
{                      //有3个数据成员
    int MAXNUM;        //用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM
    int curNum;        //用于存放顺序线性表中数据元素的个数  整型  curNum
    DataType *element; //用于存放顺序线性表数据元素的连续空间的起始地址
};

typedef struct seqList *PseqList;

/*创建空的顺序线性表，能存放的最大元素个数为 m*/
PseqList createNullList_seq(int m)
{ //若m=0，则返回NULL
    PseqList plist = (struct seqList *)malloc(sizeof(struct seqList));
    if (plist == NULL)
        return NULL; //分配空间失败
    plist->MAXNUM = m;
    plist->curNum = 0;
    plist->element = (DataType *)malloc(sizeof(DataType) * m);
    if (plist->element == NULL)
    {
        free(plist);
        return NULL;
    }
    return plist;
}

/*在线性表表尾插入数据元素,返回值0表示插入失败，返回值1表示在表尾插入成功*/
int insertP_tail(PseqList plist, int x)
{
    if (plist->curNum == plist->MAXNUM) //若表满，则无法插入
    {
        printf("list if full !");
        return 0;
    }
    plist->element[plist->curNum] = x;
    plist->curNum++;
    return 1;
}

/*回收线性表占用的空间*/
int destroyList_seq(PseqList plist)
{
    //返回值为销毁的线性表中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (plist == NULL)
        return 0;
    int m = plist->curNum;
    free(plist->element);
    free(plist);
    return m;
}

void printList_seq(PseqList plist)
{ //逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    for (int i = 0; i < plist->curNum; i++)
        printf("%d ", plist->element[i]);
}

//第一关:求顺序线性表中连续子表（最少有一个元素）的最大和并输出
int seqMaxSum(PseqList plist)
{
    int cur_sum = 0, max_num = 0, temp = 0, flag = 0;
    //int *minus_num = new int[plist->curNum];
    int minus_num[plist->curNum];
    for (int i = 0; i < plist->curNum; i++)
        if (plist->element[i] < 0)
        {
            minus_num[temp] = i;
            temp++;
            flag = 1;
        }
    for (int i = 0; i < plist->curNum; i++)
    {
        cur_sum = cur_sum + plist->element[i];
        if (cur_sum > max_num)
            max_num = cur_sum;
    }
    cur_sum = 0;
    if (flag)
        for (int k = 0; k < temp; k++)
            for (int l = minus_num[k] + 1; l < plist->curNum; l++)
            {
                cur_sum = cur_sum + plist->element[l];
                if (cur_sum > max_num)
                    max_num = cur_sum;
            }
    return max_num;
}

//第二关：寻找线性表中没有出现的最小的正整数
int findMinNumber(PseqList plist)
{ //若线性表为空，则返回0
    int i, flag = 0, max = plist->element[0];
    if (plist == NULL)
        return 0;
    for (i = 1; i < plist->curNum; i++) //寻找表中最大元素
        if (plist->element[i] > max)
            max = plist->element[i];
    /*cpp int *mark = new int[plist->curNum];*/
    int mark[max + 1]; //创建标记表，mark[0]位舍弃

    for (i = 0; i < max + 1; i++) //初始为0
        mark[i] = 0;

    for (i = 0; i < plist->curNum; i++) //标记下标
        if (plist->element[i] > 0)
            mark[plist->element[i]] = 1;
    for (i = 1; i < max + 1; i++) //标记访问
    {
        if (mark[i] == 0)
            continue;
        else
        {
            if (i - 1 > 0 && mark[i - 1] == 0)
                return i - 1;
            else if (i == max)
                return i + 1;
        }
    }
    return 0;
}

//第三关：找出给定目标值target在有序线性表中出现的起始位置和结束位置
int binarySearch(PseqList plist, int target) //二分查找
{
    int left = 0, right = plist->curNum - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (plist->element[middle] == target)
            return middle;
        else if (plist->element[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
void findPos(PseqList plist, int target, int *pos)
{
    //起始位置放在pos[0], 结束位置放在pos[1]
    pos[0] = -1;
    pos[1] = -1;
    if (plist == NULL || plist->curNum == 0)
        return;
    int star = binarySearch(plist, target);
    if (star == -1)
        return;
    int left = star;
    while (left >= 0 && plist->element[left - 1] == target)
        --left;
    pos[0] = left;
    int right = star;
    while (right <= plist->curNum - 1 && plist->element[right + 1] == target)
        ++right;
    pos[1] = right;
}
