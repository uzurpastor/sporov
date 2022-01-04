#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#include "libpr3.h"

#define STOPPING 

void shell(ssize_t BUF, char *name){
	char *command;
	char user[16];
	ssize_t cBUF = BUF + 2; // for null and \n

	if((command = (char*)malloc(sizeof(char)*BUF)) == NULL)
		stop(0, name);

	
	fprintf(stdout, "Username: ");
	fscanf(stdin, "%s", user);
	fgets(command, 2, stdin);
	printf("\tBUF %zu\n", BUF);

	while(1==1){
		printf("[%s]$ ", user);
		if(BUF <= (getline(&command, &cBUF, stdin) - 2))
			fprintf(stdout, "sorry, small buffer\n");
		else{	
			char* line = "stop";
			int i = 0;

			for(i;(command[i] == line[i]) && i < 4; i++){}
			if(i == 4)
				stop(1, name);
			else
				system(command);
		}
	}

}

void stop(int reason, char *name){
	fprintf(stdout, "Wait 3 sec...\n");
	switch(reason){
		case 1:
			fprintf(stdout, "stoppind all prosses of %s", name);
			sleep(3);
			exit(EXIT_SUCCESS);
			break;
		case 0:
			fprintf(stderr, "failed. stoppind all prosses of %s", name);
			sleep(3);
			exit(EXIT_FAILURE);
			break;
	}
}

void usage(char *name){

	printf("%s program that emulation shell\n", name);
	printf("user need write arguments of programm like\n"
		"\t-x0 \tsmall key with value\n"
		"\t--xarg=0\t long key with value\n\n");
	printf("Key of programm:\n"
		"\t-h | --help\thelp message\n"
		"\t-b | --buffer\tset file for thread of output\n");
	exit(EXIT_SUCCESS);

}




char * uread(int argc, char *argv[]){
	char *tmp;
	for(int i = 1; i < argc; i++){
		int space;
		if(i == 1){
			tmp = (char*)malloc(sizeof(argv[i]) + 1);
		}else{
			tmp = realloc(tmp,sizeof(tmp) + sizeof(argv[i]) + 1);
		}
		tmp = strcat(tmp, argv[i]);
		space = strlen(tmp);
		tmp[space] = *" ";
	}
	return tmp;

}

int find_count(char *arr){
	int value = 1;
	for(int i = 0; i < strlen(arr); i++){
		if(arr[i] == ',')
			value++;
	}
	return value;
}

void set_arr(char* thr, char *arr[], int count){
	char* cthr = thr;
	char* last = thr + strlen(thr);
	char* symbol;
	for(int i = 0; i < count; i++){
		if((symbol = strchr(thr, ',')) == NULL)
			symbol = last;
		arr[i] = (char*)malloc(symbol - thr);
		
		for(int k = 0;thr < symbol; k++, thr++){
			arr[i][k] = *thr;
		}
		thr = symbol+1;
	}
	free(cthr);
}