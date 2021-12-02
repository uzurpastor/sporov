#include "../libpr1.h"

int main(){

	int n;
	printf("num: ");
	scanf("%d", &n);

	int *arr = (int*)calloc(n, sizeof(int));
	set_arr(arr, n);
	set_randm(arr, n);

	int mvalue = find_middle(arr, n);
	int cb = count_biggest(mvalue, arr, n);

	int pos = pos_first_minus(arr, n);
	int sum_pos = sum_element_after(pos, arr, n); 

	printf("Count biggest value then middle - %d\n", cb);
	printf("Sum element after first negative - %d\n", sum_pos);

	return 0;
}