#include "libpr3.h"

char * read(int argc, char *argv[]){
	char *tmp;
	for(int i = 1; i < argc; i++){
		if(i == 1)
			tmp = (char*)malloc(sizeof(argv[i]));
		else{
			tmp = realloc(tmp,sizeof(tmp) + sizeof(argv[i]));
		}
		tmp = strcat(tmp, argv[i]);
	}
	return tmp;

}

int find_count(char *arr){
	int value = 1;
	for(int i = 0; i < strlen(arr); i++){
		if(arr[i] == ',')
			value++;
	}
	return value;
}

void set_arr(char* thr, char *arr[], int count){
	char* cthr = thr;
	char* last = thr + strlen(thr);
	char* symbol;
	for(int i = 0; i < count; i++){
		if((symbol = strchr(thr, ',')) == NULL)
			symbol = last;
		arr[i] = (char*)malloc(symbol - thr);
		
		for(int k = 0;thr < symbol; k++, thr++)
			arr[i][k] = *thr;

		thr = symbol+1;
	}
	free(cthr);
}