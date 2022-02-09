#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static void signal_handler(int signo) {
	if (signo == SIGINT){
		printf("Захвачен сигнал SIGINT!\n");
	}else if (signo == SIGTERM){
		printf("Захвачен сигнал SIGTERM!\n");
	}else {
		fprintf(stderr, "Неожиданный сигнал!\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


int main(int argc, char const *argv[]){

	if (signal(SIGINT, signal_handler) == SIG_ERR) {
		fprintf(stderr, "Невозможно обработь SIGINT!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGTERM, signal_handler) == SIG_ERR) {
		fprintf(stderr, "Невозможно обработать SIGTERM!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGPROF, SIG_DFL) == SIG_ERR) {
		fprintf(stderr, "Невозможно сбросить SIGPROF!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGHUP, SIG_IGN) == SIG_ERR) {
		fprintf(stderr, "Невозможно игнорировать SlGHUP!\n");
		exit(EXIT_FAILURE);
	}
	for (;;)
		pause();

	exit(EXIT_SUCCESS);
}
