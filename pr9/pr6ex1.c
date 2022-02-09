#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void randof(void * arg) {
  int * index = (int) * arg;
  srand(time(NULL));
  int value = rand()%10;
  sleep(index);
  pthread_exit(value);
}

int main(int argc, char const *argv[]) {


  int c_thread; // count of threads
  fprintf(stderr, "Input count of value");
  fscanf(stdin,"%d", &c_thread);

  pthread_t arr_thread[c_thread];
  int       arr_value [c_thread];

  for(int i = 0; i < c_thread;i++)
    pthread_create(&arr_thread[i], NULL, &randof, &i);

  for(int i = 0, x = 0; x != 10; i++){
    pthread_join(arr_thread[i], arr_value[i]);
  }
  pthread_create(NULL,NULL, &detached, &arr_value);

  return 0;
}
