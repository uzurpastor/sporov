#include "libpr2.h"


void case_equation(float arg[]){
	switch((int)arg[0]){
		case 0:
			printf("arguments:\n"
				"\tx1 = %g, x2 = %g", arg[1], arg[2]);
			break;
		case -1:
			printf("roots none");
			break;
		case 1:
			printf("x - all value");
			break;
		case 2:
			printf("one argument:\n"
				"\tx = %g", arg[1]);
			break;


	}
}


float* equation(float a, float b, float c, float *arg){
	if(a == 0){
		if(b == 0){
			if(c != 0){
				arg[0] = 1;
			}
			else if(c == 0){
				arg[0] = -1;
			}
		}
		else{
			arg[0] = 2;
			arg[1] = -c/b;
		}
	}
	else{
		static float x1, x2;
		float d;
		d = b * b - 4 * a * c;
		if(d < 0){
			arg[0] = -1;
		}
		else{
			if(d == 0){
				arg[0] = 2;
				arg[1] = -b/(2*a);
				
			}
			else{
				arg[0] = 0;
				arg[1] = (-b+sqrt(d))/(2*a);
				arg[2] = (-b-sqrt(d))/(2*a);
			}
		}
	}

	for(int i = 0; i < 3; i++)
		if(arg[i] == -0)
			arg[i] = 0;


	return arg;
}


void setcoef(float *p, char *optarg){
	if(optarg != NULL)
		*p = atof(optarg);
	else
		*p = 0;

}


void print_help(){
	 printf("pr2 program that use arg of comm line:\n\n"
		"\t-a\tquadratic equation coefficients\n\t-b\n\t-c\n"
		"\t-h\thelp\n"
		"\t-o\talt output data\n"
		"\t-s\tspecial working (more priority)\n"
		);
}

void special(float *pa, float *pb, float *pc){

	printf("input quadratic equation coefficients:\n");

	printf("a = ");
	scanf("%f", pa);

	printf("b = ");
	scanf("%f", pb);

	printf("c = ");
	scanf("%f", pc);

	float asw[3]; 
	/* 
		*[0] - case
		*[1] - first arg
		*[2] - second argument
	*/
	equation(*pa, *pb, *pc, asw);
	case_equation(asw);

	free(pa);
	free(pb);
	free(pc);

}

void change_stream(FILE *fp, char *name){
	if((fp = (name, 'w', stdout)) == NULL){
		perror("cannot open file");
		exit(1);
	}
}