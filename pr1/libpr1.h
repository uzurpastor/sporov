#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Min {
	int value;
	int pos;
};

void remove_item(int[], int, int);
void display_arr(char[], int[], int);
void set_arr(int[], int);
//--------unic funcs for ex2
void set_randm(int[], int);
int find_middle(int[], int);
int count_biggest(int, int[], int);
int pos_first_minus(int[], int);
int sum_element_after(int, int[], int);


int sum_element_after(int pos, int arr[], int n){
	int sum = 0;
	for(pos; pos < n; pos++){
		if(arr[pos] < 0)
			sum += -arr[pos];
		else
			sum += arr[pos];
	}
	return sum;
}


int pos_first_minus(int arr[], int n){
	int  i = 0;
	for(i; i < n; i++)
		if(arr[i] < 0)
			break;
	
	return i;
}


int count_biggest(int middle, int arr[], int n){
	int count = 0, i = 0;
	for(i; i < n; i++)
		if(arr[i] > middle)
			count++;
	return count; 
}


int find_middle(int arr[], int n){
	int sum = 0, i = 0;
	for(i; i < n;i++)
		sum += arr[i];
	sum /= n;
	return sum;
}


void set_randm(int arr[], int n){
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++)
		if(rand()%2 == 1)
			arr[i] *= -1;
}


void remove_item(int arr[], int n, int x){
	for(x; x < n; x++)
		arr[x+1] = arr[x];
	for(x; x > 0; x--){
		arr[x-1] = arr[x];
		arr[x] = 0;
	}
}


void display_arr(char * text, int arr[], int n){
	int i;
	printf("\t%s\n", text);
	for(i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}


void set_arr(int arr[], int n){
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++) arr[i] = rand();

}