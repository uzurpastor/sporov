#include "../libpr1.h"

int main(){
	FILE * fp;
	char * name = "./table";
	int step;
	struct Student arr[30];

	if((fp = fopen(name, "r")) == NULL){
		perror("ERROR: Cant find file.");
		return 0;
	}

	int n = count_strings(name);
	if(n > 30){
		perror("Chenge your file. No more than 30 values.");
		return 0;
	}

	set_stn(fp, arr, n);

	printf("_________________\n");
	display_stn(arr, n);
	printf("-----------------\n");


	while(step != 0) {
		int output;

		printf("Menu:\n"
			"\t1. Surnames of students with credo\n"
			"\t2. Percent student with nice grades\n"
			"\t3. Top1 subject\n"
			"\t4. The worst group\n"
			"\t5. Print table\n"
			"Command: ");
		scanf("%d", &step);// своровать функцию проверки 
		printf("_________________\n");
		switch (step) {
			case 1:
				fun_case1(arr, n); //Surnames of students with credo
				break;
			case 2:
				output = fun_case2(arr, n);
				printf("Percent student with nice grades %d%%\n", output);
				break;
			case 3:
				output = fun_case3(arr, n);
				printf("Top1 subject: %d\n", output);
				break;
			case 4:
				output = fun_case4(arr, n);
				printf("The worst group: %d\n", output);
				break;
			case 5:
				display_stn(arr, n);
				break;
			// default:
			//	 continue;
			case 0:
				break;
		}
		printf("-----------------\n");
	}


	fclose(fp);
	return 0;
}
