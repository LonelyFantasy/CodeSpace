#include <iostream>
#include <time.h>
/*测试生成用例*/
void create_num(int arr[], int n) //随机生成1-n内顺序数组
{
    for (int i = 1; i <= n; i++)
        arr[i - 1] = i;
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
            temp = arr[a];
            arr[a] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int n, i;
    scanf("%d", &n);
    while (n > 0)
    {
        int *data = new int[n]; //动态排序数组长度
        create_num(data, n);
        printf("全排列结果：\n");
        permutation(data, 0, n);
        scanf("%d", &n);
    }
    return 0;
}
