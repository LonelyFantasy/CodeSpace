#include "../stack.h"

int main(void)
{
	char express[80];
	gets(express);
	printf("%d",calExp(express));
}