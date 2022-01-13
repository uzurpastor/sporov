#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void usystem(char*[]);

int main(int argc, char  *argv[]){
	char* uname_args[] = {"/bin/ps", "-C", "test", NULL};
	usystem(uname_args);

	return 0;
}

void usystem(char  *argv[]){
	pid_t stream = fork();

	if(stream == -1){
		fprintf(stderr, "forking error\n");
		exit(EXIT_FAILURE);
	}

	if(stream == 0){
		execve(argv[0], argv, NULL);
		fprintf(stderr, "problem\n");
	}
	else{
		wait(NULL);
	}
}