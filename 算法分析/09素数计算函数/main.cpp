#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 2000001

void find_prime_num(int p)
{
    int i, j, data[MAX];
    memset(data, 1, sizeof(data));//使用memset批量设置所有数组为1
    for(i = 2; i <= MAX; i++)//从最小素数开始遍历所有素数
    {
        if(data[i])//判断该数字有无被筛掉或是否为已确定素数
        {
            for(j = i + i; j <= MAX; j += i)//将素数的倍数的数组值赋予为0)
                data[j] = 0;
        }
    }
    for(i = 2; i <= p; i++)
    {
        if(data[i])
            printf("%d ", i);
    }
        printf("\n");
        printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
}

 int main()
{
    int p;
    scanf("%d", &p);
    while (p)
    {
        find_prime_num(p);
        scanf("%d", &p);
    }
        return 0;
}