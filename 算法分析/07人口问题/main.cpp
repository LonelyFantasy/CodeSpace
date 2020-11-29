#include<stdio.h>
#include<math.h>
#define lli long long int
struct abc{
    int a, b, c;
    lli sum;
};

void pre_pow(lli *arr, int goal)
{
    int i = 0;
    while(i < 150)
    {
        arr[i] = pow(i + 1, goal);
        i++;
    }
}

int main()
{
    lli res[150];
    pre_pow(&res[150], 5);
    for(int i = 0; i < 150; i++)
        for(int j = 0; j < 150; j++)
            for(int k  = 0; k < 150; k++)
                for(int l = 0; l < 150; l ++)
                    for(int m = 0; m < 150; m++)
                        if(res[i] + res[j] + res[k] + res[l] == res[m])
                            printf("%d^5 + %d^5 + %d^5 + %d^5 = %d^5", i, j, k, l, m);
    return 0;
}