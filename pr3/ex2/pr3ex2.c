#include "../libpr3.h"

int main(int argc, char *argv[]){

	char *thread = uread(argc, argv);
	int count = find_count(thread);

	char *commands[count];
	set_arr(thread, commands, count);

	for(int i = 0; i < count; i++){
		system(commands[i]);

	}
	return 0;
}