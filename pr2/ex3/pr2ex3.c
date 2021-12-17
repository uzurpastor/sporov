#include "../libpr2.h"

int main(int argc, char *argv[]){
	int opt;
	FILE *fp;

	const struct option long_opt[] = {
		{"help", 0, 0, 'h'},
		{"special_output", 2, 0, 's'},
		{NULL, 0, NULL, 0}

	};

	while((opt = getopt_long(argc, argv, "ho:", long_opt, NULL)) != -1){
		switch(opt){
			case 'h':
				usagex3(argv[0]);
				break;
			case 'o':
				change_stream(fp, optarg);
				break;
			case '?':
				fprintf(stderr, "%s\n", "unknown opt");
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
