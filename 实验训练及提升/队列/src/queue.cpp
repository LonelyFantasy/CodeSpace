#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;

//队列数据元素结构
typedef struct node
{
    DataType info;
    struct node *next;
} QueueData;
typedef struct node *PseqQueue;

typedef struct queueRecord
{
    QueueData *front, *rear;
} LINKQUEUE;
typedef struct queueRecord *PLinkQueue;

PLinkQueue createEmptyQueue_link()
{
    //创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front和rear成员赋值
    PLinkQueue queue = (PLinkQueue)malloc(sizeof(struct queueRecord));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmptyQueue_link(PLinkQueue queue)
{   //判定队列是否为空，实质： 看队列的front指针是否为空，若为空，则队列为空
    /*-------begin----------*/
    if (queue->front == NULL)
        return 1;
    else
        return 0;
    /*-------end----------*/
}

void enQueue_link(DataType x, PLinkQueue queue)
{
    //将数据元素x插入队尾。实质：生成一个struct node类型的结点，并给相应成员赋值后插入队尾
    PseqQueue temp = (PseqQueue)malloc(sizeof(struct node));
    temp->info = x;
    temp->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->rear->next = temp;
        queue->rear = temp; //更新队尾
    }
}

void enQueue_link(QueueData *p, PLinkQueue Q)
{
    //本函数的功能是将 struct node 类型的结点插入队尾，与enQueue_link(DataType x, PLinkQueue queue)的区别是，不需要生成结点
    if (Q->rear)
    {
        Q->rear->next = p;
        Q->rear = p; //更新队尾
    }
    else
    {
        Q->front = p;
        Q->rear = p;
    }
}

DataType deQueue_link(PLinkQueue Q)
{
    //出队，实质： 取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData *p,PLinkQueue Q)插入队尾
    //本函数为针对本实验特殊设计，可实现秘钥的循环使用
    int num;
    num = Q->front->info;
    PseqQueue temp = Q->front;
    Q->front = Q->front->next;
    enQueue_link(temp, Q);
    return num;
}

int decrypt(char src[], char key[], char dest[])
{
    /*  参数： src 放的是源文 ； key 放的是秘钥 ； dest 放加密后的密文
        加密函数： 步骤提示
        1. 初始化一个空队列Q
        2. 将key数组的元素逐个插入队列Q
        3. 逐个访问src数组的源文，并加密， 使用deQueue_link(Q)函数可得到队首秘钥，并使秘钥循环使用
     */
    PLinkQueue list = createEmptyQueue_link();
    int cur_key, i;
    for (i = 0; i < strlen(key); i++)
    {
        if (key[i] > '0' && key[i] < '9')
        {
            int temp = key[i] - '0';
            enQueue_link(temp, list);
        }
        else
        {
            printf("Wrong");
            return 0;
        }
    }
    for (i = 0; i < strlen(src); i++)
    {
        cur_key = deQueue_link(list);
        if (src[i] >= 'a' && src[i] <= 'z')
        {
            if (src[i] + cur_key > 'z')
                dest[i] = 'a' + (src[i] + cur_key - 'z' - 1);
            else
                dest[i] = src[i] + cur_key;
        }
        else if (src[i] >= 'A' && src[i] <= 'Z')
        {
            if (src[i] + cur_key > 'Z')
                dest[i] = 'A' + (src[i] + cur_key - 'Z' - 1);
            else
                dest[i] = src[i] + cur_key;
        }
        else
        {
            printf("Wrong");
            return 0;
        }
    }
    dest[i] = '\0';
    return 1;
}

int main(void)
{
    char src[80], key[20], dest[80];
    cin >> src;
    cin >> key;
    int temp;
    temp = decrypt(src, key, dest);
    if (temp == 1)
        cout << dest;
    else
        return 1;
}
