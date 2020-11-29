#include <stdio.h>
#include <stdlib.h>
struct node
{ //链表结点类型，包含一个存放整型数据的 data 成员，和指向前驱和后继结点的指针
    int data;
    struct node *llink, *rlink;
};

struct Hnode
{ //双向链表头结点,有两个指针成员，分别指向双向链表的第一个结点和最后一个结点
    struct node *head, *tail;
};

//第二关代码
struct Hnode *createDlist()
{ //函数功能：创建一个带头结点的双向链表，tail指向尾结点；head指针指向第一个结点，返回值是指向头结点的指针
    struct Hnode *head;
    struct node *body;
    head = (struct Hnode *)malloc(sizeof(struct Hnode));
    body = (struct node *)malloc(sizeof(struct node));
    head->head = body;
    head->tail = body;
    body->llink = NULL;
    body->rlink = NULL;
    return head;
}

void insertDlist(struct Hnode *list, int insData)    //在双向链表的表头插入数据
{
    struct node *create = (struct node *)malloc(sizeof(struct node));
    create->data = insData; //插入data
    create->llink = NULL;   //新建节点左link定义
    create->rlink = list->head;//新建节点右link定义
    list->head->llink = create; //原第一个节点llink重定义
    list->head = create;        //头结点重重指向
}

int deleteData(struct Hnode *list, int delData)//在双向链表中删除值为delData的第一个结点，若删除成功返回1，否则返回0
{
    struct node *p, *q; //当前节点、前驱结点
    p = list->head;            //指向第一个数据
    while (p != NULL && p->data != delData)
    {
        q = p; //保存前驱节点
        p = p->rlink;
    }
    if (p == NULL)
        return 0;
    else if (p->llink == NULL) //头结点指向第一个数据为del时操作
    {
        p->rlink->llink == NULL; //后继节点当头数据
        list->head = p->rlink;   //头节点指向
        free(p);
        return 1;
    }
    else if (p->rlink == NULL) //当数据在尾结点时操作
    {
        list->tail = q; //头节点tail指向删除节点前驱
        q->rlink = NULL;
        free(p);
        return 1;
    }
    else //del夹在已有数据中
    {
        p->llink->rlink = p->rlink;
        p->rlink->llink = p->llink;
        free(p);
        return 1;
    }
}

void printDlist(struct Hnode *list)//输出双向循环链表中各数据元素的值，每输出一个数据元素换一行
{
    struct node *p;
    p = list->head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->rlink;
    }
}

int destroyDlist(struct Hnode *list)
{ //释放双向链表占用的存储空间，释放所有结点,返回释放的结点数，不含list本身
    struct node *head, *temp;
    int num = 0;
    head = list->head;
    while (head != NULL)
    {
        temp = head;
        head = head->rlink;
        free(temp);
        num++;
    }
    list->head = NULL;
    list->tail = NULL;
    return num-1;
}