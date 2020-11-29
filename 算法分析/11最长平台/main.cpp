/*概念解释
已知一个已经从小到大排序的数组，这个数组的一个平台（Plateau）就是连续的一串值相同的元素，并且这一串元素不能再延伸。
例如，在 1，2，2，3，3，3，4，5，5，6中1，2-2，3-3-3，4，5-5，6都是平台。
试编写一个程序，接收一个数组，把这个数组最长的平台找出来。在上面的例子中3-3-3就是最长的平台。
输入
第一行有一个整数n(n <= 1000)，为数组元素的个数。第二行有n个整数，整数之间以一个空格分开。
输出
输出最长平台的长度。
*/
#include <stdio.h>
#define MAX 1000
int main()
{
    int n, p, flag, temp, i;           //数组长度n、平台位置p、位置辅助判断flag、temp
    int curlenth, maxlenth, data[MAX]; //当前长度cur、最长长度max
    while (1)
    {
        scanf("%d", &n);
        if (n == 0) //非法输入
            return 0;
        for (i = 0; i < n; i++)
            scanf("%d", &data[i]);
        p = 1;        //初始化位置记录
        curlenth = 1; //初始化当前长度
        maxlenth = 1; //初始化最长平台
        flag = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (data[i] == data[i + 1]) //连续判断
            {
                curlenth++;
                flag++;
                if (flag == 1)
                    temp = i + 1;
            }
            else
            {
                curlenth = 1;
                flag = 0;
            }
            if (curlenth > maxlenth) //平台判断
            {
                maxlenth = curlenth;
                p = temp;
            }
        }
        printf("平台位置：%d, 长度：%d\n", p, maxlenth);
    }
    return 0;
}