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

struct elem{
	int value;
	pthread_rwlock_t lock;
};

typedef unsigned short int cthread_t;
typedef unsigned short int count_t;

count_t * count_elem_p = NULL;

void check_arg(int argc, char *argv[]);

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


void main(int argc, char *argv[])
{
	struct elem * main_arr;
	pthread_t * thread_write_arr, * thread_read_arr, thread_detouch;
	cthread_t count_write, count_read;

	check_arg(argc, argv);
	count_t count_elem = *count_elem_p;

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


void usage()
{

	printf("user need write arguments of programm like\n"
		"\t-x0 \tsmall key with value\n"
		"\t--xarg=0\t long key with value\n\n");
	printf("Key of programm:\n"
		"\t-h | --help\thelp message\n"
		"\t-b | --buffer\tset file for thread of output\n");
	exit(EXIT_SUCCESS);

}


void check_arg(int argc, char *argv[])
{
	count_t count_elem = 10;

	int opt;
	struct option l_opt[] = {
		{"help", 0, 0, 'h'},
		{"buffer", 2, 0, 'b'},
		{NULL, 0, NULL, 0}
	};

	while((opt = getopt_long(argc, argv, "hb:", l_opt, NULL)) != -1){
		switch(opt){
			case 'h':
				usage();
			break;
			case 'b':
				count_elem = (count_t)atoi(optarg);
			break;
			case ':':
				fprintf(stderr, "Need argument");
				exit(EXIT_FAILURE);
			break;
			case '?':
				fprintf(stderr, "%s\n", "unknown opt");
			break;
		}
	}
	count_elem_p = &count_elem;
}


void kill_arr(pthread_t * arr_of_thread, cthread_t count_of_thead)
{
	for(count_t i = 0; i < count_of_thead; i++){
		kill(arr_of_thread[i], SIGINT);
	}
}


void mutex_destroy(struct elem * main_arr)
{
	count_t count_elem = *count_elem_p;

	for(count_t i = 0; i < count_elem; i++){
		if(pthread_rwlock_destroy(&main_arr[i].lock) != 0){
			fprintf(stderr, "mutexdestroyERR\n");
			exit(EXIT_FAILURE);
		}
	}
}


void mutex_init(struct elem * main_arr)
{
	count_t count_elem = *count_elem_p;

	for(count_t i = 0; i < count_elem; i++){
		if(pthread_rwlock_init(&main_arr[i].lock, NULL) != 0){
			fprintf(stderr, "mutexinitERR\n");
			exit(EXIT_FAILURE);			
		}
		main_arr[i].value = 0;
	}

	for(count_t i = 0; i < count_elem; i++){
		fprintf(stderr, "mutex init  %d[%d]\n", i , main_arr[i].value);	
	}
}


void * write_func(void * data)
{
	srand(time(NULL));
	
	struct elem * main_arr = (struct elem *)data;
	count_t count_elem = *count_elem_p;

	while(1==1)
	{
		int time_sleep, elem;

		time_sleep = rand()%3;
		sleep(time_sleep);

		elem =  rand()%count_elem;

		if(pthread_rwlock_wrlock(&main_arr[elem].lock) != 0){
				fprintf(stderr, "wrlockERR\n");
				exit(EXIT_FAILURE);
		}else{
			main_arr[elem].value++;
			fprintf(stderr, "writting %d[%d]\n", elem, main_arr[elem].value);
			
			if(pthread_rwlock_unlock(&main_arr[elem].lock) != 0){
					fprintf(stderr, "unlockERR\n");
					exit(EXIT_FAILURE);
			}
		}
	}
}


void * read_func(void * data)
{
	srand(time(NULL));
	
	struct elem * main_arr = (struct elem *)data;
	count_t count_elem = *count_elem_p;
	
	while(1==1)
	{
		int time_sleep, elem;

		time_sleep = rand()%3;
		sleep(time_sleep);

		elem = rand()%count_elem;
		if(pthread_rwlock_rdlock(&main_arr[elem].lock) != 0){
			fprintf(stderr, "rdlockERR\n");
			exit(EXIT_FAILURE);
		}else{
			fprintf(stderr, "printing %d[%d]\n", elem, main_arr[elem].value);
				
			if(pthread_rwlock_unlock(&main_arr[elem].lock) != 0){
				fprintf(stderr, "unlockERR\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}


void * detouched_func(void * data)
{
	srand(time(NULL));
	
	struct elem * main_arr = (struct elem *)data;
	count_t count_elem = *count_elem_p;
	int time_sleep;
	char * buf;

	while(1==1)
	{
		time_sleep = rand()%5;
		sleep(time_sleep);

		for(count_t i = 0; i < count_elem; i++){
			if(pthread_rwlock_rdlock(&main_arr[i].lock) != 0){
				fprintf(stderr, "rdlockERR %d\n", i);
				exit(EXIT_FAILURE);
			}
		}

		fprintf(stderr, "\tAll array:\n\t%s\n", create_buf(buf, main_arr));

		for(count_t i = 0; i < count_elem; i++){
			if(pthread_rwlock_unlock(&main_arr[i].lock) != 0){
				fprintf(stderr, "unlockERR\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char * create_buf(char * buf, struct elem * main_arr)
{
	count_t count_elem = *count_elem_p;
	int len = 0;

	for(int i = 0; i < count_elem; i++){
		char tmp[8];
		
		sprintf(tmp, "%d ", main_arr[i].value);
		for(int j = 0; tmp[j] != '\0'; j++, len++){}

		if(buf == NULL){
			if((buf = (char *)malloc(sizeof(tmp))) == NULL){
				fprintf(stderr, "mallocERR\n");
				exit(EXIT_FAILURE);
			}
		}else{
			buf = realloc(buf, sizeof(buf) + sizeof(tmp));
		}
		buf = strcat(buf, tmp);
	}
	return buf;
}

void pthreads_init(pthread_t arr_thread[], cthread_t count_thead, char type, struct elem * main_arr)
{
	switch(type){
		case 'w':
			if((arr_thread = (pthread_t*)malloc(sizeof(pthread_t)*count_thead)) == NULL){
				fprintf(stderr, "mallocERR\n");
				exit(EXIT_FAILURE);
			}

			for(count_t i = 0; i < count_thead; i++){
				if(pthread_create(&arr_thread[i], NULL, &write_func, main_arr)){
					fprintf(stderr, "SOMERROR thread - %d\n", i);
					exit(EXIT_FAILURE);
				}
			}
		break;
		case 'r':
			if((arr_thread = (pthread_t*)malloc(sizeof(pthread_t)*count_thead)) == NULL){
				fprintf(stderr, "mallocERR\n");
				exit(EXIT_FAILURE);
			}

			for(count_t i = 0; i < count_thead; i++){
				if(pthread_create(&arr_thread[i], NULL, &read_func, main_arr)){
					fprintf(stderr, "SOMERROR thread - %d\n", i);
					exit(EXIT_FAILURE);
				}
			}
		break;
		case 'd':
			
		break;
	}
}

void pthreads_detouch_init(pthread_t thread, struct elem * main_arr)
{
	pthread_attr_t attr_4detouch;

	if(pthread_attr_init(&attr_4detouch) != 0){
		fprintf(stderr, "attrinitERR\n");
		exit(EXIT_FAILURE);		
	}
	
	if(pthread_attr_setdetachstate(&attr_4detouch, PTHREAD_CREATE_DETACHED) != 0){
		fprintf(stderr, "setdetachstateERR\n");
		exit(EXIT_FAILURE);		
	}

	if(pthread_create(&thread, &attr_4detouch, &detouched_func, main_arr)){
		fprintf(stderr, "SOMERROR thread\n");
		exit(EXIT_FAILURE);
	}

	if(pthread_attr_destroy(&attr_4detouch) != 0){
		fprintf(stderr, "destroy_attrERR\n");
		exit(EXIT_FAILURE);		
	}
}
