#include <stdio.h> 
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <math.h>

void print_help(void);
void setcoef(float*, char*);
float* equation(float, float, float, float*);
void case_equation(float[]);
void special(float*, float*, float*);
void change_stream(FILE*, char*);