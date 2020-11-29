#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct seqStack
{
    DataType *element;
    int top;
    int Maxnum;
};

typedef struct seqStack *PseqStack;
//第一关
PseqStack createNullStack_seq(int m)
{   //此处填写代码，创建一个空的顺序栈，能存放的最大元素个数为 m,栈顶top设置为0
    //若m=0，则返回NULL
    PseqStack L = (struct seqStack *)malloc(sizeof(struct seqStack));
    L->top = -1;
    L->element = (int *)malloc(sizeof(int) * m);
    L->Maxnum = m;
    return L;
}

//第二关
int isNullStack_seq(PseqStack L)
{
    //判断顺序栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
    if (L->top == -1)
        return 1;
    else
        return 0;
}

//第三关
int isFullStack_seq(PseqStack L)
{
    //判断顺序栈是否已满，若已满，返回值为1，否则返回值为0
    if (L->top == L->Maxnum)
        return 1;
    else
        return 0;
}

//第四关
int push_seq(PseqStack L, DataType x)
{ //在顺序栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1

    if (isFullStack_seq(L))
        return 0;
    L->element[L->top + 1] = x;
    L->top++;
}

//第五关
DataType pop_seq(PseqStack L)
{ //弹栈并返回删除元素，若栈为空，则返回-1
    if (isNullStack_seq(L))
        return -1;
    L->top--;
    return L->element[L->top + 1];
}

//第六关
DataType top_seq(PseqStack L)
{ // 取栈顶元素返回，若栈为空，则返回-1
    if (isNullStack_seq(L))
        return -1;
    else
        return L->element[L->top];
}

int up_count(int a, int x, int y)
{
    if (x == 1)
        return a;
    if (x == 2)
        return y;
    else
        return up_count(a, x - 1, y) + up_count(a, x - 2, y);
}
//main 函数中调用result 函数，输出第x站时车上的人数
/*参数n:  一共n站
      m:  最后一站下车人数
      a:  第一站上车人数
      x:  求第x站时车上的人数
*/
int result(int n, int m, int a, int x)
{
    int *up = (int *)malloc(sizeof(int) * m);
    int t, p, i;
    int count = 0;
    PseqStack L = createNullStack_seq(m);
    int flag = 1;
    for (t = 0; t < m && flag; t++)
    {
        L->top = -1;
        push_seq(L, a);
        push_seq(L, a);
        for (i = 1; i < n; i++)
        {
            up[i] = up_count(a, i, t);
            if (i > 2)
            {
                count = top_seq(L) + up[i] - up[i - 1];
                push_seq(L, count);
            }
        }
        if (m == up[1] + up[n - 1] - t)
        {
            flag = 0;
            p = n - 1;
            while (isNullStack_seq(L) == 0)
            {
                count = pop_seq(L);
                if (p == x)
                {
                    return count;
                }
                p--;
            }
        }
    }
}