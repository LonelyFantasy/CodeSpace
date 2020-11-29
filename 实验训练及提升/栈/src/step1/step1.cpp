#include "../stack.h"

int main()
{
   int n,m,a,x ;//分别表示n站，最后一站下车的人数m，始发站上车人数a，求第x站时车上的人数
   scanf("%d%d%d%d",&n,&m,&a,&x);
   printf("%d",result(n,m,a,x));
}
