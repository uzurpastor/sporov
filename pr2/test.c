#include <stdio.h>
#include <stdlib.h>

void main(){
	
	FILE *fp;
	// char *name = "stdout";

	if((fp = freopen("stdout", "w", stdout)) == NULL){
		printf("cannot open file");
		exit(1);
	}
	printf("testd");
	printf("34567890");
	fclose(fp);
	// return 0;
}