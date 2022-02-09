#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int prime_num(int num){
	if(num == 1) 
		return 1;

	for(int i=2; i<=num/2; i++){
		if(num%i == 0){
			return 0;
		}
	}

	return 1;
}

void * fun1 (void * args){
	int * value = (int*)args;	
	int * arr = (int*)malloc(sizeof(int)*1);
	int arr_elem = 1;

	for(int i = 1; i <= *value; i++){
		if(prime_num(i)){
			arr_elem++;
			arr = (int*)realloc(arr, sizeof(int)*arr_elem);
			arr[arr_elem-1] = i; 
		}
	}	
	arr[0] = arr_elem;

	pthread_exit(arr);
}

void main(void){

	int value1 = 50, value2 = 100;
	int * prime_arr1, * prime_arr2;
	pthread_t thread1, thread2;
	
	if(pthread_create(&thread1, NULL, &fun1, &value1) != 0){
		fprintf(stderr, "SOMERROR\n");
		exit(EXIT_FAILURE);
	}

	if(pthread_create(&thread2, NULL, &fun1, &value2) != 0){
		fprintf(stderr, "SOMERROR\n");
		exit(EXIT_FAILURE);
	}
	
	if(!pthread_equal(pthread_self(), thread1)){
		void * result;
		pthread_join(thread1, &result);
		prime_arr1 = (int*)result;
	}

	if(!pthread_equal(pthread_self(), thread2)){
		void * result;
		pthread_join(thread2, &result);
		prime_arr2 = (int*)result;
	}

	{	fprintf(stderr, "value1 = 50\n");
		for(int i = 1; i < prime_arr1[0]; i++){
			fprintf(stderr,"%d ", prime_arr1[i]);
		}
		fprintf(stderr, "\n");
	}

	{	fprintf(stderr, "value2 = 100\n");
		for(int i = 1; i < prime_arr2[0]; i++){
			fprintf(stderr,"%d ", prime_arr2[i]);
		}
		fprintf(stderr, "\n");
	}

	free(prime_arr1);
	free(prime_arr2);

}