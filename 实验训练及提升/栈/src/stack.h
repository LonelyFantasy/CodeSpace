#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 自己定义需要的栈结构，及栈基本操作函数，假设操作数都是整数

int mycmp(char a, char b) //计算用
{
    if (b == '(')
        return 1; //左括号直接入栈
    else if ((b == '*' || b == '/') && (a == '+' || a == '-' || a == '('))
        return 1; //*、/优先级高于+、-、(，入栈
    else if ((b == '+' || b == '-') && (a == '('))
        return 1; //+、-优先级高于(，入栈
    else
        return 0;
}

//转化后缀
void inToPost(char *express, char *result)
{
    int i, k, j = 0, top = 0;
    char stack[1000]; //存储运算符的栈
    for (i = 0; express[i] != '\0'; i++)
    {
        if (express[i] >= '0' && express[i] <= '9')
        {
            result[j++] = express[i]; //操作数则直接输出
        }
        else
        {
            if (i != 0 && express[i - 1] >= '0' && express[i - 1] <= '9')
            {
                result[j++] = ' '; //操作数后补充空格分割
            }
            if (express[i] == ')')
            {
                //遇到右括号则一直弹出直到左括号，但左括号不输出
                while (stack[top - 1] != '(')
                {
                    result[j++] = stack[--top];
                    result[j++] = ' ';
                }
                top--;
            }
            else if (top == 0 || mycmp(stack[top - 1], express[i]))
            {
                //栈为空或当前操作符的优先级高于栈顶操作符，当前操作符入栈
                stack[top++] = express[i];
            }
            else
            {
                //当前操作符优先级等于或低于栈顶操作符则弹出栈顶
                while (!mycmp(stack[top - 1], express[i]))
                {
                    result[j++] = stack[--top];
                    result[j++] = ' ';
                    if (top == 0)
                        break;
                }
                stack[top++] = express[i]; //当前操作符入栈
            }
        }
    }
    //补充空格分割
    if (result[j - 1] != ' ')
    {
        result[j++] = ' ';
    }
    //如果操作符栈不为空，弹出所有操作符
    while (top != 0)
    {
        result[j++] = stack[--top];
        result[j++] = ' ';
    }
    result[j] = '\0';
}


int caculate(char *result)
{
    int i, j;
    char op;
    int stack[1000];
    int top = 0, value = 0;
    for (i = 0; result[i] != '\0'; i++)
    {
        if (result[i] >= '0' && result[i] <= '9')
        {
            value = value * 10 + result[i] - '0';
        }
        else if (result[i] == ' ')
        {
            //操作数入栈
            stack[top++] = value;
            value = 0;
        }
        else
        {
            //根据操作符，对栈顶两个操作数进行计算并得到结果
            switch (result[i])
            {
            case '+':
                value = stack[top - 2] + stack[top - 1];
                break;
            case '-':
                value = stack[top - 2] - stack[top - 1];
                break;
            case '*':
                value = stack[top - 2] * stack[top - 1];
                break;
            case '/':
                value = stack[top - 2] / stack[top - 1];
                break;
            default:
                break;
            }
            top -= 2;
        }
    }

    return stack[0];
}

int calExp(char *express)
{
    char result[1000];
    inToPost(express, result);
    return caculate(result);
}