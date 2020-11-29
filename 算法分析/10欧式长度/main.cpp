#include <stdio.h>
#include <math.h>
using namespace std;
double calculate(double x[], double y[], double z[], int n)
{
    double result, temp = 0;
    int i;
    /*输入部分*/
    if (n == 3)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &x[0], &y[0], &z[0], &x[1], &y[1], &z[1]);
    }
    else
    {
        for (i = 0; i < n; i++)
            scanf("%lf %lf", &x[i], &y[i]);
    }
    /*判断部分*/
    if (n > 3) //n维空间
    {
        for (i = 0; i < n; i += 2)
        {
            temp = pow(x[i] - y[i], 2);
        }
    }
    else if (n == 3) //三维空间
        temp = pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2) + pow(z[1] - z[0], 2);
    else if (n == 2) //二维空间两个点
        temp = pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2);
    else
        temp = pow(x[0], 2) + pow(y[0], 2);
    result = sqrt(temp);
    return result;
}

int main()
{
    int n;
    double result;
    scanf("%d", &n);
    if (n > 0)
    {
        do
        {
            double *x = new double[n]; //创建动态长度数组
            double *y = new double[n];
            double *z = new double[n];
            printf("欧式长度：%.4lf\n", result = calculate(x, y, z, n));
            scanf("%d", &n);
        } while (n);
    }
    else
        return 0;
}
