
#include <stdio.h>

int fun(void){
	int n =0;
	return n++;
}

void main(void)
{
    printf("%d", fun());
}
