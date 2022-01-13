#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <time.h>

int main(void){
	time_t now = time(NULL);
	pid_t forkid = fork();
	
	int i = 0;
	while((time(NULL)-now) < 1){
		i ++;
		if(forkid == 0){
			printf("forked - %d\n", i);
		}else
			printf("main - %d\n", i);
	}
	
	return 0;
}