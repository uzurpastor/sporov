#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <time.h>

int main(void){

	int local = 7;
	printf("%d\n", local);

	pid_t forkid = fork();
	
	
	{
	
		local++;
		if(forkid == 0){
			printf("\tII.%d\n", local);
		}else
			printf("\tI.%d\n", local);
		

		{
			forkid = fork();
			local++;
			if(forkid == 0){
				printf("\t\tII.%d\n", local);
			}else
				printf("\t\tI.%d\n", local);
					
		}


	}


	return 0;
}
