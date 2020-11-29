#include <stdlib.h>
#include <stdio.h>

//存放多项式某项的结点结构
struct node
{
	int exp;		   // 表示指数
	int coef;		   //表示系数
	struct node *next; //指向下一个结点的指针
};
//5 0 2 1 3 5 -2 7 0 0 12 1 2 7 13 15 0 0
//6 -1 5 0 7 9 0 0 -15 -2 9 9 18 12 0 0
typedef struct node *PNODE;

/*
  函数功能：生成多项式
  函数名：createPoly
  函数参数：无
  返回值：指向多项式的头指针 
*/
PNODE createPoly(void)
{
	//在此处填写代码，能实现创建一个多项式并返回多项式头指针的函数
	//注意：头指针不存放多项式的项。
	/**********  Begin **********/
	int exp, coef, cur;
	struct node *head, *p1, *p2;
	head = (PNODE)malloc(sizeof(PNODE));
	if (head != NULL)
	{
		head->exp = 0;
		head->coef = 0;
		head->next = NULL;
	}
	p1 = (PNODE)malloc(sizeof(PNODE));
	head->next = p1;
	p1->exp = 0;
	p1->coef = 0;
	cur = -10;
	scanf("%d", &coef);
	scanf("%d", &exp);
	while (coef)
	{
		for (; cur < exp; cur++)
		{
			p2 = (PNODE)malloc(sizeof(PNODE));
			p2->next = NULL;
			p1->next = p2;
			p1 = p1->next;
			p1->exp = cur + 1;
			p1->coef = 0;
		}
		p1->exp = exp;
		p1->coef = coef;
		scanf("%d", &coef);
		scanf("%d", &exp);
	}
	return head;
	/**********  End  **********/
}

/*
   函数功能：进行多项式相加
   函数名：addPoly
   函数参数：polyAddLeft ：加法左边多项式头指针, polyAddRight：加法右边多项式头指针 
   返回值：指向结果多项式的头指针 
*/
PNODE addPoly(PNODE polyAddLeft, PNODE polyAddRight)
{
	//在此处填写代码，能实现创两个多项式相加并返回结果多项式头指针的函数
	/**********  Begin **********/
	struct node *head, *p1, *p2;
	int i;
	head = (PNODE)malloc(sizeof(PNODE));
	p1 = (PNODE)malloc(sizeof(PNODE));
	head->exp = 0;
	head->coef = 0;
	p1 = head;
	i = 0;
	if (polyAddLeft != NULL)
		polyAddLeft = polyAddLeft->next;
	if (polyAddRight != NULL)
		polyAddRight = polyAddRight->next;
	do
	{
		p2 = (PNODE)malloc(sizeof(PNODE));
		p2->next = NULL;
		p1->next = p2;
		p1 = p1->next;
		if (polyAddLeft != NULL && polyAddRight != NULL)
			p1->coef = polyAddLeft->coef + polyAddRight->coef;
		else if (polyAddLeft != NULL && polyAddRight == NULL)
			p1->coef = polyAddLeft->coef;
		else if (polyAddLeft == NULL && polyAddRight != NULL)
			p1->coef = polyAddRight->coef;
		p1->exp = i;
		i++;
		if (polyAddLeft != NULL)
			polyAddLeft = polyAddLeft->next;
		if (polyAddRight != NULL)
			polyAddRight = polyAddRight->next;
	} while (polyAddLeft != NULL || polyAddRight != NULL);
	return head;
	/**********  End **********/
}

/*
   函数功能：输出多项式 
   函数名：printPoly
   函数参数：待输出多项式的头指针poly 
   返回值：无 
*/
void printPoly(PNODE poly)
{
	//在此处填写代码，能实现按格式输出多项式的功能，输出格式样例见说明
	/**********  Begin **********/
	poly = poly->next;
		do
		{
			if (poly->coef != 0)
			{
				printf("%d", poly->coef);
				printf("x^%d", poly->exp - 10);
			}
			if (poly->coef && poly->next != NULL)
				printf("+");
			poly = poly->next;
			if (poly == NULL)
				break;
		} while (poly != NULL);
	/**********  End **********/
}

void destroyPoly(PNODE poly)
{
	//释放存储多项式的链表空间
	PNODE current = poly, temp, head = poly;
	int data;
	current = poly;
	while (current->next != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
}