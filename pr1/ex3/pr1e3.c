#include "../libpr1.h"

int main(){
  FILE * fp;
  char * name = "./table";
  int i, step, output;
  struct Student arr[30];

  if((fp = fopen(name, "r")) == NULL){
    perror("ERROR: Cant find file.");
    return 0;
  }

  int n = count_strings(name);
  if(n > 30){
    perror("Chenge your file. No more than 30 values.");
    return 0;
  }

  set_stn(fp, arr, n);
  display_stn(arr, n);

  do {
    printf("Menu:\n\
      \t1. Students with credo\n\
      \t2. Percent student with nice grades\n\
      \t3. Top1 subject\n\
      \t4. The worst group\n"
      "Command:");
      scanf("%d\n", &step);

    switch (step) {
      case 1:
        output = fun_case1(fn, arr, n); ;//////////////////stoped//////////////
      default:
        continue;

    }
  } while(step == 0);


  fclose(fp);
  return 0;
}
