// pr4ex7_1.c
// child

#include "libex7.h"

int main(int argc, char  *argv[]){

	int sum, x1, x2;
	x1 = atoi(argv[0]);
	x2 = atoi(argv[1]);
	sum = x1 + x2;
	printf("%d\n", sum);
	
	
	exit(sum);

}