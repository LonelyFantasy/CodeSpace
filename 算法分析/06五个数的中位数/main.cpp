//  main.cpp
//  06 中位数
//  Created by Lonely_Fantasy on 2020/9/23.
//  System: macOS 10.15.6

#include <stdio.h>
void swap(int *l, int *r);
void comp(int *l, int *r);
int main(int argc, const char * argv[]) {
    int data[5], i, temp;
    for(i = 0; i < 5; i++){scanf("%d", &data[i]);}
    //求中位数，让前三个确定大小顺序，第四第五个顺序可不管，因为第三个小于第四第五数
    //前四个分组排序
    comp(&data[0], &data[1]);//1
    comp(&data[2], &data[3]);//2
    //两组谁最小判断
    temp = data[0];
    comp(&data[0], &data[2]);//3
    if(temp != data[0]){swap(&data[1], &data[3]); }//4
    //end此时，data[0]在前四个中最小
    comp(&data[1], &data[4]);//较小者放入data[1]
    //比较第二个和第三个数谁大，如果发生变化，第三个和第五个也跟着变化//
    temp = data[1];
    comp(&data[1], &data[2]);
    if(temp != data[1])swap(&data[3], &data[4]);
    //最后交换第三个和第五个数字
    comp(&data[2], &data[4]);
    for(i = 0; i < 5; i++){printf("%d ", data[i]);}putchar('\n');
    printf("中位数为%d\n", data[2]);
    return 0;
}

void swap(int *l, int *r){//交换函数
    int temp;
    temp = *r; *r = *l; *l = temp;
}
void comp(int *l, int *r){//比较函数
    
    if(*l > *r)swap(l, r);
}
