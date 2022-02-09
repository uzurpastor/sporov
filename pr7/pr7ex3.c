#include"libpr7.h"

#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<sys/types.h>


void main(int argc, char *argv[])
{
	struct elem * main_arr;
	pthread_t * thread_write_arr, * thread_read_arr, thread_detouch;
	cthread_t count_write, count_read;

	count_t count_elem;
	count_init(argc, argv, &count_elem);

	if((main_arr = (struct elem*)malloc(sizeof(struct elem)*count_elem)) == NULL){
		fprintf(stderr, "mallocERR\n");
		exit(EXIT_FAILURE);
	}else
		mutex_init(main_arr);

	fprintf(stderr, "thread_write_arr: ");
	fscanf(stdin,"%hu", &count_write);

	fprintf(stderr, "thread_read_arr: ");
	fscanf(stdin,"%hu", &count_read);

	pthreads_init(thread_write_arr, count_write, 'w', main_arr);
	pthreads_init(thread_read_arr, count_read, 'r', main_arr);
	pthreads_detouch_init(thread_detouch, main_arr);

	sleep(15);
	fprintf(stderr, "exiting\n");
	
	kill(thread_detouch, SIGINT);
	pthread_join(thread_detouch, NULL);

	kill_arr(thread_write_arr, count_write);
	kill_arr(thread_read_arr, count_read);
	mutex_destroy(main_arr);
	free(main_arr);
	free(thread_write_arr);
	free(thread_read_arr);
}
