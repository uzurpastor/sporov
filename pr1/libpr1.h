#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

	struct Min { //struct for ex0
	int value;
	int pos;
};

struct Student{ //struct for ex3
	char surname[12];
	int group;
	int grade1;
	int grade2;
	int grade3;
};

struct ArrayList{ //struct for ex4
	int value;
	struct ArrayList * next;
};

	//---funcs for ex0---//
	//-------START-------//
void display_arr(char[], int[], int);
void set_arr(int[], int);
void remove_item(int[], int, int); //func for ex0
	//--------END--------//

	//---funcs for ex2---//
	//-------START-------//
void set_arr(int[], int);
void set_randm(int[], int);
int find_middle(int[], int);
int count_biggest(int, int[], int);
int pos_first_minus(int[], int);
int sum_element_after(int, int[], int);
	//--------END--------//


	//---funcs for ex3---//
	//-------START-------//
int count_strings(char *);
char * concatf(char*, char*, char*, char*);
void display_stn(struct Student *, int);
void set_stn(FILE *, struct Student *, int);
void fun_case1(struct Student *, int);
int fun_case2(struct Student *, int);
int fun_case3(struct Student *, int);
int fun_case4(struct Student *, int);
int compare(int sum[][3], int);
int find_countofgroup(struct Student *, int);

	//--------END--------//


	//---funcs for ex4---//
	//-------START-------//
struct ArrayList * init(int);
void add(struct ArrayList *, int);
void display_list(struct ArrayList *);
struct ArrayList * find_lastelem(struct ArrayList *);

	//--------END--------//
