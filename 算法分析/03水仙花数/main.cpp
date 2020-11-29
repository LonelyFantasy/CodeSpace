//
//  main.cpp
//  水仙花数
//
//  Created by Lonely_Fantasy on 2020/9/20.
//
#include<iostream>
#include<time.h>
using namespace std;


int main(int argc, const char * argv[]) {
    //算法3
    int a,b,c,i,j,k;
    for ( a=1;a<10;a++)
    {
        i = a*a*a;
        for ( b=0;b<10;b++)
        {
            j = b*b*b;
            for ( c=0;c<10;c++)
            {
                k = a*100+b*10+c*1;
                if(i + j +c*c*c == k)
                    cout<<k<<endl;
            }
        }
    }
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
