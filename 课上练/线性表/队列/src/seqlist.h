#include <stdio.h>
#include <stdlib.h>

/*此处是顺序队列数据结构定义*/
typedef int DataType;
struct seqQueue //请完成数据结构定义
{
    int MAXNUM;        //用于记录顺序队列中能存放的最大元素个数，整型
    int front, rear;   //用于存放顺序队列的队首，队尾
    DataType *element; //用于存放数据元素的连续空间的起始地址
};

typedef struct seqQueue *PseqQueue;
//第一关
PseqQueue createNullQueue_seq(int m)
{ //此处填写代码，创建一个空的顺序队列，能存放的最大元素个数为 m
    //若m=0，则返回NULL
    if (m == 0)
        return NULL;
    PseqQueue head = (PseqQueue)malloc(sizeof(struct seqQueue));
    head->MAXNUM = m;
    head->front = head->rear = 0;
    head->element = (DataType *)malloc(sizeof(DataType) * head->MAXNUM);
    return head;
}

//第二关
int isNullQueue_seq(PseqQueue Q)
{
    //判断顺序（环形）队列是否为空，若为空，返回值为1，否则返回值为0,若队列不存在，则返回-1
    if (Q == NULL)
        return -1;
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

//第三关
int isFullQueue_seq(PseqQueue Q)
{
    //判断环形队列是否已满，若已满，返回值为1，否则返回值为0
    if ((Q->rear + 1) % Q->MAXNUM == Q->front)
        return 1;
    else
        return 0;
}

//第四关
int enQueue_seq(PseqQueue Q, DataType x)
{ //在环形队列中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if (isNullQueue_seq(Q) == -1)
        return 0;
    if (isFullQueue_seq(Q))
        return 0;
    else
    {
        Q->element[Q->rear] = x;
        Q->rear = (Q->rear + 1) % Q->MAXNUM;
        return 1;
    }
}

//第五关
DataType delQueue_seq(PseqQueue Q)
{ //出队并返回删除元素，若队列为空，则返回-1
    int res;
    if (isNullQueue_seq(Q))
        return -1;
    else
    {
        res = Q->element[Q->front];
        Q->front = (Q->front + 1) % Q->MAXNUM;
        return res;
    }
}

//第六关
DataType front_seq(PseqQueue Q)
{ // 取队首元素返回，若队列为空，则返回-1
    if (isNullQueue_seq(Q))
        return -1;
    else
        return Q->element[Q->front];
}

//销毁顺序队列，释放队列所占存储空间
int destroyQueue_seq(PseqQueue Q)
{
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (isNullQueue_seq(Q))
        return 0;
    int res = (Q->front + Q->rear + 2) / 2;
    free(Q->element);
    free(Q);
    return res;
}

//第七关
void queueApp(int a[], int n)
{
    //参数用于传递顾客编号和顾客人数，输出顾客接受服务后离开顺序
    PseqQueue A, B;
    int i, count = 0, flag = 0;
    A = createNullQueue_seq(n+1);//由于占用一个空数组作为队尾，创建时需要多创建一个位置
    B = createNullQueue_seq(n+1);//由于占用一个空数组作为队尾，创建时需要多创建一个位置
    for (i = 0; i < n; i++) //入队
    {
        if (a[i] % 2 == 0)
            enQueue_seq(B, a[i]);
        else
            enQueue_seq(A, a[i]);
    }
    while (isNullQueue_seq(A) == 0 && isNullQueue_seq(B) == 0)//AB队列不为空
    {
        printf("%d ", front_seq(A));
        delQueue_seq(A);
        if (isNullQueue_seq(A) != 1)
        {
            printf("%d ", front_seq(A));
            delQueue_seq(A);
        }
        printf("%d ", front_seq(B));
        delQueue_seq(B);
    }
    while (isNullQueue_seq(A) == 1 && isNullQueue_seq(B) != 1)//队列A为空
    {
        printf("%d ", front_seq(B));
        delQueue_seq(B);
    }
    while (isNullQueue_seq(A) != 1 && isNullQueue_seq(B) == 1)//队列B为空
    {
        printf("%d ", front_seq(A));
        delQueue_seq(A);
    }
}
