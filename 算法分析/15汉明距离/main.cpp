/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char arr[], int a, int n) //排列函数
{
    if (a == n)
    {
        printf("%c", arr[0]);
        for (int i = 1; i < n; i++)
            printf(" %c", arr[i]);
        putchar('\n');
    }
    else
    {
        for (int i = a; i < n; i++)
        {
            char temp = arr[a];
            arr[a] = arr[i];
            arr[i] = temp;
            permutation(arr, a + 1, n); //递归入口
            temp = arr[a];
            arr[a] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);
    char *data = new char[n]; //生成初始长度为n长度的全0二进制字符串
    for (int i = 0; i < n - 1; i++)
        data[i] = 0;
    for (int i = 0; i < k; i++)
    {
        data[i] = 1;
        permutation(data, 0, n);
    }
    return 0;
}
*/

#include <iostream>
#include <time.h>
/*测试生成用例*/
void create_num(int arr[], int n) //随机生成1-n内顺序数组
{
    for (int i = 1; i <= n; i++)
        arr[i - 1] = 0;
}
/*结束*/

void permutation(int arr[], int a, int n) //排列函数
{
    if (a == n)
    {
        printf("%d", arr[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", arr[i]);
        putchar('\n');

    }
    else
    {
        for (int i = a; i < n; i++)
        {
            int temp = arr[a];
            arr[a] = arr[i];
            arr[i] = temp;
            permutation(arr, a + 1, n); //递归入口
        }
    }
}
int main()
{
    int n, i, k;
    scanf("%d", &n);
    int *data = new int[n]; //动态排序数组长度
    create_num(data, n);
    scanf("%d", &k);
    for (i = 0; i < k; i++) //将k个1依次加进去并全排列
    {
        data[i] = 1;
    }
    permutation(data, 0, n);
    return 0;
}