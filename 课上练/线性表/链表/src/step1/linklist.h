#include <stdio.h>
#include <stdlib.h>
struct node
{ //链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
};
typedef struct node List;

void sortList(List *head, List *flag)//去头节点地址，带头节点保存尾节点
{
    List *p = head;
    List *q = head;
    int temp;
    for (; p->next != flag; p = p->next)
    { // 确定比较次数
        for (q = head; q->next != flag; q = q->next)
        {
            if (q->data > q->next->data)
            {
                temp = q->data;
                q->data = q->next->data;
                q->next->data = temp;
            }
        }
    }
}

struct node *createRlist()
{ //函数功能：创建一个有一个空循环链表，返回值为头指针
    struct node *head;
    head = (struct node *)malloc(sizeof(List));
    head->next = head;
    return head;
}

void insertOrder(struct node *list, int insData) //无问题
{
    //在单向递增有序的循环链表（表头指针list）中插入数据元素insData，使之依然有序 。
    List *head, *current, *temp;
    current = list;
    while (current->next != list) //访问表尾
        current = current->next;
    temp = (struct node *)malloc(sizeof(List));
    current->next = temp;
    temp->data = insData;
    temp->next = list;
    sortList(list->next, list);
}

int deleteData(struct node *list, int delData)
{

    int dele_num = 0; //删除数量统计
    List *current, *temp;
    current = list; //代替list
    temp = current;
    current = current->next;
    while (current != list) //开始遍历
    {
        if (current->data == delData) //判断是否为删除的数据
        {
            temp->next = current->next;
            dele_num++;
        }
        else
            temp = current;
        current = current->next;
    }
    return dele_num;
}

void printRlist(struct node *list) //无问题
{
    //从链表第一个结点开始输出单向循环链表中各数据元素的值，每输出一个数据元素换一行
    List *p;
    p = list->next;
    while (p != list)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int destroyRlist(struct node *list)
{
    //从第一个结点开始释放循环链表各结点占用的空间,返回值为最后一个结点的值
    List *current = list, *temp, *head = list;
    int data;
    current = list;
    while (current->next != head)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    data = current->data;
    free(current);
    return data;
}
