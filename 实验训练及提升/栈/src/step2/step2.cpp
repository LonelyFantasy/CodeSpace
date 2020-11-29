#include "../stack.h"

int main(void)
{
	char express[80];
    gets(express);
   // printf("%s",express);
	Stack s = inToPost(express);
    print(s);
}