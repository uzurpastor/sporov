
#include <stdio.h>

int fun(void){
    int n =0;
    return n++;
}

void main(void)
{
    int x = sizeof("abc") > -1  ;

    printf("%f", (double)x);
}
