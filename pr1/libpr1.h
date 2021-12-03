#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Min { //struct for ex0
	int value;
	int pos;
};

struct Student{
	char surname[12];
	int group;
	int grade1;
	int grade2;
	int grade3;
};

//--------funcs for ex0-------//
//-------START-------//
void display_arr(char[], int[], int);
void set_arr(int[], int);
void remove_item(int[], int, int); //func for ex0
//--------END--------//

//--------funcs for ex2-------//
//-------START-------//
void set_arr(int[], int);
void set_randm(int[], int);
int find_middle(int[], int);
int count_biggest(int, int[], int);
int pos_first_minus(int[], int);
int sum_element_after(int, int[], int);
//--------END--------//


//--------funcs for ex3-------//
//-------START-------//
int count_strings(char *);
char * concatf(char*, char*, char*, char*);
void display_stn(struct Student *, int);
void set_stn(FILE *, struct Student *, int);
int fun_case1(FILE *, struct Student *, int);
//--------END--------//


int fun_case1(FILE * fp, struct Student * arr, int n){
	int i;
	int count = 0;//////////////////stoped//////////////
}


void set_stn(FILE * fp, struct Student * arr, int n){
	int i;
	for(i = 0; i < n; i++)
    fscanf(fp, "%s %d %d %d %d",
       arr[i].surname,
      &arr[i].group,
      &arr[i].grade1,
      &arr[i].grade2,
      &arr[i].grade3);

}


void display_stn(struct Student * arr, int n){
	int i;
	for(i = 0; i < n; i++)
    printf("%s \t %d\t %d\t %d\t %d\n",
      arr[i].surname,
      arr[i].group,
      arr[i].grade1,
      arr[i].grade2,
      arr[i].grade3);
}


char* concatf4(char* t1, char* t2, char* t3, char* t4){

	int len1 = strlen(t1);
  int len2 = strlen(t2);
  int len3 = strlen(t3);
  int len4 = strlen(t4);

	char * sum = (char*)malloc(sizeof(char)*(len1 + len2 + len3 + len4));
	sum = strcat(sum, t1);
	sum = strcat(sum, t2);
	sum = strcat(sum, t3);
	sum = strcat(sum, t4);

	return sum;
}


int count_strings(char * name){
	FILE * fp;
	int count;

	char * system_out = "system_out";
	char * command = concatf4("wc -l ", name, " >> ./", system_out);

	system(command);
	free(command);

	if((fp = fopen(system_out, "r")) == NULL){
		perror("ERROR: Cant find file.");
		return 0;
	}

	fscanf(fp, "%d", &count);
	fclose(fp);

	// command = concatf4("rm -r ", system_out, "", "");
	system("rm -r system_out");
	/*сложность создания такой же строки как в первом случае
		* вывод:
		* sh: 1: 5: not found
		* malloc(): corrupted top size
		* make: *** [Makefile:5: all] Аварийный останов (сделан дамп памяти)
	*/

	return count;
}


int sum_element_after(int pos, int arr[], int n){
	int sum = 0;
	for(pos; pos < n; pos++){
		if(arr[pos] < 0)
			sum += -arr[pos];
		else
			sum += arr[pos];
	}
	return sum;
}


int pos_first_minus(int arr[], int n){
	int  i = 0;
	for(i; i < n; i++)
		if(arr[i] < 0)
			break;

	return i;
}


int count_biggest(int middle, int arr[], int n){
	int count = 0, i = 0;
	for(i; i < n; i++)
		if(arr[i] > middle)
			count++;
	return count;
}


int find_middle(int arr[], int n){
	int sum = 0, i = 0;
	for(i; i < n;i++)
		sum += arr[i];
	sum /= n;
	return sum;
}


void set_randm(int arr[], int n){
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++)
		if(rand()%2 == 1)
			arr[i] *= -1;
}


void remove_item(int arr[], int n, int x){
	for(x; x < n; x++)
		arr[x+1] = arr[x];
	for(x; x > 0; x--){
		arr[x-1] = arr[x];
		arr[x] = 0;
	}
}


void display_arr(char * text, int arr[], int n){
	int i;
	printf("\t%s\n", text);
	for(i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}


void set_arr(int arr[], int n){
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++) arr[i] = rand();

}
