#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TIME 1000000//试验发生次数
int main() {
    int a, b, i, j, k;
    int first = 0, second = 0, temp;//记录事件成功的次数
    double res1, res2;//概率保存
    srand((unsigned int)time(NULL));
    //开始投掷
    //第一种假设为事件：“投6次骰子至少有1个1”；第二种假设为事件：“投12次至少有2个1”
    for (i = 0; i < TIME; i++)//发生TIME次事件
    {
        temp = 0;
        for (j = 0; j < 6; j++)//事件1
        {
            a = rand() % 6 + 1;
            if (a == 1)
            {
                first++;
                break;
            }
        }
        //end事件1
        
        for (k = 0; k < 12; k++)//事件2
        {
            b = rand() % 6 + 1;
            if (b == 1)
                temp++;
            if (temp == 2) { second++; break; }
        }//end事件2

    }
    res1 = (double)first / TIME;
    res2 = (double)second / TIME;
    printf("事件数%d的情况下，第一种事件的概率为%.5lf，第二种事件的概率为%.5lf\n", TIME, res1, res2);
    return 0;
}

