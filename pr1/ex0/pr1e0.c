#include "../libpr1.h"


int main(){

	int n, i, tmp;
	struct Min x;
	printf("num: ");
	scanf("%d", &n);

	int *arr;
	arr = (int*)calloc(n, sizeof(int));

	set_arr(arr, n);
	display_arr("input:", arr, n);	

	for(i = 0, x.value = arr[i]; i < n; i++){
		if(x.value >= arr[i]){
			x.value = arr[i];
			x.pos = i;
		}
	}
	remove_item(arr, n, x.pos);
	n = 1;

	display_arr("output:", arr, n);	
	free(arr);

}
