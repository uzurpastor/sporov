#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<signal.h>
#include<sys/types.h>
#include<getopt.h>
#include<errno.h>

typedef unsigned short int cthread_t;
typedef unsigned short int count_t;

struct elem{
	int value;
	pthread_rwlock_t lock;
};

void count_init(int argc, char *argv[], count_t * count);

void pthreads_init(pthread_t * arr_of_thread, cthread_t count_of_thead, char type, struct elem * main_arr);
void pthreads_detouch_init(pthread_t thread, struct elem * main_arr);

void mutex_init(struct elem * p_arr);
void mutex_destroy(struct elem * p_arr);
void kill_arr(pthread_t * arr_of_thread, cthread_t count_of_thead);

void * write_func(void * data);
void * read_func(void * data);
void * detouched_func(void * data);
char * create_buf(char str[], struct elem * main_arr);

void usage();
