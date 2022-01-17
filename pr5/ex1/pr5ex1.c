#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <string.h>


int main(void)
{
	#ifdef __USE_POSIX
	printf("\n\nPOSIX USE\n\n");
#else
	printf("\n\nPOSIX NOT USE\n\n");
#endif

	pid_t pid = fork();
	switch(pid){
		case -1:
			fprintf(stderr, "fork");
			exit(EXIT_FAILURE);
			break;
		case 0:	execl("./sigin", "./sigin");
			break;
		default:{
			int status, status_kill, sig;
			fprintf(stderr, "Pick signal: \n");
			fprintf(stderr,
				"\t1) SIGHUP(ignored)\n"
				"\t2) SIGINT\n"
				"\t15) SIGTERM\n"
				"\t27) SIGPROF(default)\n"
			);
			scanf("%d", &sig);

			status_kill = kill(pid, sig);
			if(status_kill == -1){
				fprintf(stderr, "problem :%d", errno);
			}else{
				fprintf(stderr, "signal send\n");
			}

			waitpid(pid, &status, 0);
			fprintf(stderr, "waited");
			if(WEXITSTATUS(status)){
				fprintf(stderr, "normal exit of thr");
			}
		}
	}
	return EXIT_SUCCESS;
}
