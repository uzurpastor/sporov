// pr4ex7_1.c
// main file
#include "libex7.h"


int main(int argc, char const *argv[]){
	
	int status;
	char* arv[3];
	//how???????
	arv[0] = (char*)malloc(sizeof(char)*3);
	arv[1] = (char*)malloc(sizeof(char)*3);
	arv[2] = NULL;

	fprintf(stdout, "Put value 1: ");
	fscanf(stdin, "%s", arv[0]);

	fprintf(stdout, "Put value 2: ");
	fscanf(stdin, "%s", arv[1]);
	
	
	pid_t pid = fork();
	if(pid == -1){
		fprintf(stderr, "forking error\n");
		exit(EXIT_FAILURE);
	}

	if(pid == 0){
		execv("./pr4ex7_2", arv);
		fprintf(stderr, "problem\n");
		exit(EXIT_FAILURE);
	}else
		waitpid(pid, &status, 0);
		printf("tasktomakeandreybesitsaURE%d", status);

	return 0;
}