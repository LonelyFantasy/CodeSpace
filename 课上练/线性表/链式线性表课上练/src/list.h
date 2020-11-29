#include <stdio.h>
#include <stdlib.h>
//第一关代码

struct node
{//此处填写代码，定义链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
};

struct node *mycreateList()
{//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    struct node* head;
  struct node* Head;
  Head = (struct node*)malloc(sizeof(struct node));
  Head->data = 0;
  Head->next = NULL;
  return Head;
}


//第二关代码

void myinsertHead(struct node * head, int insData )
{
	/*在此处完成任务，实现在head为表头d 链表的头插数据元素insData的功能*/
	//begin
       struct node *create, *read;
    read = head;
    create = (struct node*)malloc(sizeof(struct node));//数据块
    create->data = insData;
    create->next = read->next;
    read->next = create;
	//end 
}

void myinsertTail(struct node *  head , int insData )
{
	/*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
	//begin
       struct node *create, *read;
    read = head;
    create = (struct node*)malloc(sizeof(struct node));//数据块
    create->data = insData;
    create->next = NULL;
    while(read->next != NULL)//读取
        read = read->next;
    read->next = create;
	//end 	
}

void myprintList(struct node *L)
{
     /*在此处完成任务，输出head为表头链表中的数据，每输出一个数据换一行*/
	//begin
	    struct node *read;
    read = L;
    for(read = read->next; read != NULL; read = read->next)
     printf("%d\n", read->data);
	//end
}

//第三关代码
 void reverseList_link( struct node *L)
 {
    //请在此处填入代码，实现链表逆置功能 
 	//begin
 	struct node *p,*q,*r;
	p = L->next;
	if(p == NULL)
		return;
	q = p->next;
	p->next = NULL;
	while(q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	L->next=p;
	//end 
 }


//第四关代码
int locateAndChange( struct node *L, int data)
 {
    //在头结点为L的链表中查找 与data值相等的第一个结点，若能找到该结点，则将该结点的值与前驱结点的值交换
    //若未找到与data值相等的结点，则返回值为-1，若找到的结点无前驱结点，则返回值为0，否则返回值为前驱结点的值
 	//begin
	struct node *current = L;
	int temp;
	while (current->next != NULL)//遍历开始
	{
		if(current->next->data == data)//判断data是否相等
		{
			if(current != L)//判断前驱结点是否为头结点(data是否为空)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				return temp;//返回交换前的前驱结点
			}
			else
				return 0;//前驱结点为空
			}
			current = current->next;
	}
	return -1;
	//end
 }

//第五关代码
int destroyList(struct node *L)
{
  //请在此处填写代码，实现将链表L的结点空间回收
 //返回值为回收结点的个数，含头结点在内
  int del_num = 0;
  struct node *current = L, *temp;
  while (current != NULL)
  {
	  temp = current;
	  free(temp);
	  del_num++;
	  current = current->next;
  }
  free(current);
  return del_num;
}

