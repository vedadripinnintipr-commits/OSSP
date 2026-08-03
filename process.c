#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    char command[100];

    printf("Enter Linux command: ");
    scanf("%s", command);

    pid = fork();

    if(pid < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }

    if(pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child PID = %d\n", getpid());

        execlp(command, command, NULL);

        printf("Command execution failed.\n");
    }
    else
    {
        wait(NULL);

        printf("\nParent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
    }

    return 0;
}
