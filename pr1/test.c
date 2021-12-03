#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

  char * x1 = "qwerty";
  char * x2, * x4;
  char * x3 = "123456";

  x2 = "asd";
  x4 = "zxc";

  char * sum;
  int len1 = strlen(x1);
  int len2 = strlen(x2);
  int len3 = strlen(x3);
  int len4 = strlen(x4);
  sum = (char*)malloc(sizeof(char)*(len1 + len2 + len3 + len4));
  sum = strcat(sum, x1);
  sum = strcat(sum, x2);
  sum = strcat(sum, x3);
  sum = strcat(sum, x4);

  printf("%s\n", sum);

  free(sum);
  return 0;
}
