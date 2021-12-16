#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char const *argv[]){
	
	if(argc != 4){
		perror("ERROR! Only 2 values for sum");
		return 0;
	}
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	float c = atof(argv[3]);

	if(a == 0)
		if(b == 0)
			if(c == 0)
				printf("x - all value");
			else if(c != 0)
				printf("roots none");
		else
			printf ("x = %g", -c/b);
	else{
		static float x1, x2;
		float d;
		d = b * b - 4 * a * c;
		if(d < 0)
			printf("roots none");
		else
			if(d == 0)
				printf("x= %g", -b/(2*a));
			else
				printf("x1= %g, x2= %g",\
					(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
	}
	return 0;
}