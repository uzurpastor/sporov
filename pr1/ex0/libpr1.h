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