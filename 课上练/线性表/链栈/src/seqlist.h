#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*此处是链栈数据结构定义*/
typedef int DataType;
struct node
{
    DataType info;
    struct node *link;
};
typedef struct node *PNode; //结点类型
struct LinkStack
{
    PNode top;
};
typedef struct LinkStack *PLinkStack; //栈顶链栈类型
//第一关
PLinkStack createNullStack_link()
{ //此处填写代码，创建一个空的链栈
    PLinkStack plstack = (PLinkStack)malloc(sizeof(struct LinkStack));
    if (plstack != NULL)
        plstack->top = NULL;
    else
        printf("falue to creat");
    return plstack;
}

//第二关
int isNullStack_link(PLinkStack L)
{ //判断栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
    if (L == NULL)
        return -1;
    else if (L->top)
        return 0;
    else
        return 1;
}

//第三关
int push_link(PLinkStack L, DataType x)
{ //在栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    PNode p = (PNode)malloc(sizeof(struct node));
    if (p == NULL)
        return 0;
    else
    {
        p->info = x;
        p->link = L->top;
        L->top = p;
    }
    return 1;
}

//第四关
DataType pop_link(PLinkStack L)
{            //弹栈并返回删除元素，若栈为空，则返回-1
    PNode p; //暂存栈顶元素
    int data;
    if (isNullStack_link(L) == 1)
        return -1;
    else
    {
        p = L->top;
        data = p->info;
        L->top = L->top->link;
        free(p);
    }
    return data;
}

//第五关
DataType top_link(PLinkStack L)
{ // 取栈顶元素返回，若栈为空，则返回-1
    PNode p;
    if (L->top)
        return L->top->info;
    else
        return -1;
}

//销毁栈，释放栈所占存储空间
int destroystack_link(PLinkStack L)
{
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    int cnt = 0;
    if (L == NULL)
        return 0;
    struct node *p = L->top, *q;
    if (p == NULL)
        return 0;
    free(L);
    while (p->link != NULL)
    {
        q = p->link;
        cnt++;
        free(p);
        p = q;
    }
    return cnt;
}

//第六关

int balance_symbol(char *s)
{ //在此处填写代码完成符号配对判断，若配对，返回值为1，否则返回值为0
    int i, length = strlen(s);
    PLinkStack head = createNullStack_link();
    for (i = 0; i < length - 1; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            push_link(head, s[i]);
        if (s[i] == '}')
        {
            if (top_link(head) == '{')
                pop_link(head);
            else
                return 0;
        }
        else if (s[i] == ']')
        {
            if (top_link(head) == '[')
                pop_link(head);
            else
                return 0;
        }
        else if (s[i] == ')')
        {
            if (top_link(head) == '(')
                pop_link(head);
            else
                return 0;
        }
    }
    return 1;
}
