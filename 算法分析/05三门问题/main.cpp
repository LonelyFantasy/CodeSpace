//  main.cpp
//  05 三门问题
//  Created by Lonely_Fantasy on 2020/9/22.
//  System: macOS 10.15.6

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TIME 100000//游戏试验次数
#define GAME_OVER continue//决策后结束当前游戏试验

int main()
{
    srand((unsigned int)time(NULL));
    int door[3] = { 0, 0, 0 };//建立三个空门
    int bestdoor, selectdoor, nonedoor;//有奖品的门、参赛人选择的门、无奖品的门
    int selection;//策略选择
    int res1 = 0, res2 = 0;//策略1、2分别成功次数记录
    double a, b;
    int i, j, temp, coun1 = 0, coun2 = 0;//coun记录选择该决策次数
    //试验开始
    for (i = 0; i < TIME; i++)
    {
        //每次游戏初始化门
        for (j = 0; j < 3; j++) { door[j] = 0;}
        //设置有奖品的门（使用0、1表示）
        bestdoor = rand() % 3;
        door[bestdoor] = 1;
        //参赛人进行选择门号
        selectdoor = rand() % 3;
        //主持人打开无奖品的门
        for (j = 0; j < 3; j++) { if (door[j] == 0 && j != selectdoor) { nonedoor = j; break; } }
        //随机选择策略
        selection = rand() % 2;//0、1为不换门和换门（抛硬币）
        //策略一：不换门
        if (selection == 0) {coun1++;
            if (door[selectdoor] == 1) {
                res1++;
                GAME_OVER;
            }
            else
                GAME_OVER;
        }
        //策略2：换门
        if (selection == 1) {coun2++;
            //换到最后没选的那扇门
            temp = 3 - selectdoor - nonedoor;//选择最后那扇未选的门
            if (door[temp] == 1) {
                res2++;
                GAME_OVER;
            }
            else
                GAME_OVER;
        }
    }
    /*试验结束，求概率*/
    a = (double)res1 / TIME;
    b = (double)res2 / TIME;
    printf("选择不换门的策略，在%d次游戏中，选择该决策的次数为%d，得到奖品的次数为%d，在决策次数中的占比为%.4lf，整个试验中占比%.4lf\n", TIME, coun1, res1, a * 2, a);
    printf("选择换门的策略，在%d次游戏中，选择该决策的次数为%d，得到奖品的次数为%d，在决策次数中占比为%.4lf，整个试验中占比%.4lf\n", TIME, coun2, res2, b * 2, b);
    return 0;
}

