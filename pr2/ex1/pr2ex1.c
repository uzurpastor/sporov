#include "../libpr2.h"


int main(int argc, char const *argv[]){
	
	if(argc != 4){
		perror("ERROR! Only 3 values for fun");
		exit(0);
	}
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	float c = atof(argv[3]);
	float asw[3] = {0};

	equation(a, b, c, asw);
	case_equation(asw);

	return 0;
}