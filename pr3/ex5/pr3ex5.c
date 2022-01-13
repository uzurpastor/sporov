#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

#include "../libpr3.h"

char* default_file_name = "./default.txt";

int main(int argc, char *argv[]){
	int opt;
	struct option l_opt[] = {
		{"file", 1, 0, 'f'},
		{"number", 2, 0, 'n'},
		{NULL, 0, NULL, 0}
	};
	char* file_name;	
	file_name = (char*)malloc(sizeof(default_file_name));
	file_name = default_file_name;

	while((opt = getopt_long(argc, argv, "f::n:", l_opt, NULL)) != -1){
		switch(opt){
			case 'f':
				file_name = (char*)realloc(file_name, strlen(optarg));
				file_name = optarg;			
				break;
			case 'n':
				
				break;
			case ':':
				fprintf(stderr, "Need argument"); 
				exit(EXIT_FAILURE);
				break;
			case '?':
				fprintf(stderr, "%s\n", "unknown opt");
				exit(EXIT_FAILURE);
				break;
			default:
				break;

		}
	}
	return 0;
}