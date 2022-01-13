#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

#include "../libpr3.h"

ssize_t BUF = 127;

int main(int argc, char *argv[]){
	int opt;
	struct option l_opt[] = {
		{"help", 0, 0, 'h'},
		{"buffer", 2, 0, 'b'},
		{NULL, 0, NULL, 0}
	};

	while((opt = getopt_long(argc, argv, "hb:", l_opt, NULL)) != -1){
		switch(opt){
			case 'h':
				usage(argv[0]);
				break;
			case 'b':
				BUF = (ssize_t)atoi(optarg);
				shell(BUF, argv[0]);
				break;
			case ':':
				fprintf(stderr, "Need argument"); ////STOP
				stop(0, argv[0]);
				break;
			case '?':
				fprintf(stderr, "%s\n", "unknown opt");
				break;
			default:
				shell(BUF, argv[0]);
				break;

		}

	}
	shell(BUF, argv[0]);
	return 0;
}