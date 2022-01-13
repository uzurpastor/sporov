/* gcc pr4ex3b.c -o test */


#include <sys/types.h>
#include <unistd.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

pid_t fun(int);
void systemcat(char*, char*);

int main(int argc, char *argv[]){

	unsigned short int count;
	fprintf(stdout, "COunt of stream: ");
	scanf("%hd", &count);

	pid_t pidstrm = getpid();
	pid_t x = fun(count);

	if(x == pidstrm){
		sleep(1);
		system("ps -C test");		
		system("killall test");
	}else
		while(1==1);


	return 0;
}

void systemcat(char* str, char* name){

	str = strcat(str, name);
	system(str);
}


pid_t fun(int count){
	count--;
	
	pid_t stream = fork();

	if(stream == -1){
		fprintf(stderr, "forking error\n");
		exit(EXIT_FAILURE);
	}

	pid_t pidstrm = getpid();
	if(stream == 0 && count > 0){
		fun(count);
	}else{
		return pidstrm;
	}

}