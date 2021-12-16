#include "../libpr2.h"

int main(int argc, char *argv[]){
	int opt;
	int check = 0;
	FILE *fp;

	float *pa = (float*)malloc(sizeof(float));
	float *pb = (float*)malloc(sizeof(float));
	float *pc = (float*)malloc(sizeof(float));

	while((opt = getopt(argc, argv, ":a:b:c:ho::s")) != -1){ 
		switch(opt){ 
			case 'a':
				setcoef(pa, optarg);
				check++;
				break; 
			case 'b': 
				setcoef(pb, optarg);
				check++;
				break;
			case 'c': 
				setcoef(pc, optarg);
				printf("%s", optarg);
				check++;
				break; 
			case 'h':
				usagex2(argv[0]);
				break;
			case 'o':
				printf("%s\n", optarg);
				if((fp = ((char*)optarg, 'w', stdout)) == NULL){
					perror("cannot open file");
					exit(1);
				}
				break;
			case 's':
				special(pa, pb, pc);
				return 0;
				break;
			case ':': 
				printf("option needs a value\n"); 
				break; 
			case '?': 
				printf("unknown option: %c\n", optopt);
				break; 
		} 
	} 

	if(check == 0){
		free(pa);
		free(pb);
		free(pc);
		exit(1);
	}else{
		float asw[3]; 
		/* 
			*[0] - case
			*[1] - first arg
			*[2] - second argument
		*/
		equation(*pa, *pb, *pc, asw);
		case_equation(asw);
		
		if(fp != NULL)
			fclose(fp);
		free(pa);
		free(pb);
		free(pc);
	}
	return 0;
}

