#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 自己定义需要的栈结构，及栈基本操作函数，假设操作数都是整数
typedef char DataType;
struct stack
{
    int MAXNUM;        //用于记录顺序栈中能存放的最大元素个数的 整型 MAXNUM
    int top;           //用于存放顺序栈的栈顶位置，初始化为0或-1 均可  整型  curNum
    DataType *element; //用于存放顺序栈数据元素的连续空间的起始地址
};
typedef struct stack *Stack;

Stack createNullStack_seq(int m)
{   //此处填写代码，创建一个空的顺序栈，能存放的最大元素个数为 m,栈顶top设置为0
    //若m=0，则返回NULL
    Stack palist = (Stack)malloc(sizeof(struct stack));
    if (m == 0)
        return NULL;
    palist->MAXNUM = m;
    palist->top = 0;
    palist->element = (DataType *)malloc(sizeof(DataType));
    return palist;
}

void push_seq(Stack L, DataType x)
{ //在顺序栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    L->element[L->top] = x;
    L->top++;
}

DataType pop_seq(Stack L)
{ //弹栈并返回删除元素，若栈为空，则返回-1
    L->top--;
    return L->element[L->top];
}

DataType top_seq(Stack L)
{ // 取栈顶元素返回，若栈为空，则返回-1
    if (L->top == 0)
        return -1;
    return L->element[L->top - 1];
}
/*在此定义并完成第一关函数，参考main要求*/

/*
   第二关
   函数名：inToPost，本函数名和参数不能更改
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：返回放有后缀表达式的栈
*/
Stack inToPost(char *expression)
{
    //在此处填写代码，完成中缀表达式转换为后缀表达式并输出
    /**********  Begin  **********/
    Stack list = createNullStack_seq(strlen(expression) + 1);
    for (int i = 0; expression[i] != '\0';)
    {
        if (expression[i] == '(') //括号检测，内部运算优先级变为最高
        {
            push_seq(list, expression[i]); //入栈
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (expression[i] == '+' || expression[i] == '-')
            {
                while (list->top != 0)
                    printf("%c ", pop_seq(list));
            }
            push_seq(list, expression[i]);
        }
        else if (expression[i] == ')') //检测结束括号，进行括号内弹出并输出
        {
            while (top_seq(list) != '(')
                printf("%c ", pop_seq(list));
        }
        else
        {
            while (expression[i] >= '0' && expression[i] <= '9')
            {
                printf("%c", expression[i]);
                i++;
            }
            printf(" ");
            continue;
        }
        i++;
    }
    return list;
    /**********  End  **********/
}

//print函数用于输出后缀表达式，参数是 inToPost的返回值
void print(Stack s)
{
    while (s->top != 0)
        printf("%c ", pop_seq(s));
}
