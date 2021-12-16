#include <stdio.h>
#include <stdlib.h>

void main(){
	
	FILE *fp;
	// char *name = "stdout";

	if((fp = ("stdout", 'w', stdout)) == NULL){
		printf("cannot open file");
		exit(1);
	}
	printf("test");
	fclose(fp);
	// return 0;
}