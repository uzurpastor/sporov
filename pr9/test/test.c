#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


int main(void)
{
  #ifdef __USE_POSIX
	printf("\n\nPOSIX USE\n\n");
#else
	printf("\n\nPOSIX NOT USE\n\n");
#endif
    pid_t pid = -1;

    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        goto err0;
    }
    else if (0 == pid)
    {
        while(1)
        {
            printf("child process do thing --- Hello uplooking\n");
            sleep(1);
        }

        exit(0);
    }

    printf("parent process do thing\n");

    sleep(3);

    // Отправляем указанный сигнал указанному процессу
    //kill(pid, SIGKILL);
    kill(pid, 9);

    return 0;
err0:
    return 1;
}
