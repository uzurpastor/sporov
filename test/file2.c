#include <stdio.h>
#include "file1.h"
int main()
{
    extern int callCount;
    printf("%d\n", callCount);
    someFunction();
    printf("%d\n", callCount);
    return 0;
}