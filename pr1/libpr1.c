#include "libpr1.h"

int fun_case3(struct Student * arr, int n){
	float subject[3] = {0};
	float tmp;
	int top = 1;

	for(int i = 0; i < n; i++){
		subject[0] += arr[i].grade1;
		subject[1] += arr[i].grade2;
		subject[2] += arr[i].grade3;
	}

	for(int i = 0; i < 3; i++)
		subject[i] /= n;
			
	tmp = subject[0];
	for(int i = 0; i < 3; i++){
		if(tmp < subject[i]){
			tmp = subject[i];
			top = i + 1;
		}
	}

	return top;
}


int compare(int arr[][3], int n){
	float middle;
	int num = 0;

	for(int i = 0; i < n; i++){
		float tmp;
		tmp = (float)arr[i][0]/(float)arr[i][1];
		
		if(i == 0){
			middle = tmp;
			num = arr[i][2];

		}else if(tmp < middle){
			middle = tmp;
			num = arr[i][2];
		}
	}
	return num;

}


int find_countofgroup(struct Student * group, int n){
	int arr[n];
	int x = n;

	for(int i = 0; i < n; i++)
		arr[i] = group[i].group;

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(arr[i] == arr[j])
				x--;

	return x;
}


int fun_case4(struct Student * arr, int n){
	int wgroup;
	int COUNT = find_countofgroup(arr, n);

	int (*sum)[3] = (int (*)[3])malloc(COUNT*3*sizeof(int));

	for(int k, i = 0; i < n; i++){
		k = arr[i].group - 1;
		sum[k][0] += arr[i].grade1 + arr[i].grade2 + arr[i].grade3;
		sum[k][1] += 3;
		sum[k][2] = k + 1;
	}
	wgroup = compare(sum, COUNT);
	free(sum);
	return wgroup;
}


int fun_case2(struct Student * arr, int n){
	int perc;
	int count = 0;

	for(int i = 0; i < n; i++){
		if((arr[i].grade1 >= 10 && arr[i].grade1 <= 12)
			|| (arr[i].grade2 >= 10 && arr[i].grade2 <= 12)
			|| (arr[i].grade3 >= 10 && arr[i].grade3 <= 12))
			count ++;
	}
	perc = (int)(count*100)/n;
	return perc;

}


void fun_case1(struct Student * arr, int n){
	for(int j = 1, i = 0; i < n; i++){
		if(arr[i].grade1 == 0 || arr[i].grade2 == 0 || arr[i].grade3 == 0){
			printf("%d. %s\n", j, arr[i].surname);
			j++;
		}
	}
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
	int i = 0;
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
