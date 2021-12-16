#include "../libpr2.h"

int main(int argc, char const *argv[]){
	int opt;
	while((c = getopt()) != -1){
		switch(opt){
			case 'h':
				usage(argv[0]);
				break;
			case '?':
				fprintf(stderr, "%s\n", "unknown opt");
		}
	}

	return 0;
}
