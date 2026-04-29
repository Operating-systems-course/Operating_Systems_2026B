#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    printf("before\n");
    pid = fork();
    printf("%d\n", pid);
    printf("Hello\n");

    if (pid < 0)
    {

        return 1;
    }
    else if (pid == 0)
    {
        printf("PID -> (%d) Hello child \n", pid);
        execlp("ls","ls","-l",NULL);
        return 1;
    }
    else
    {
        wait(NULL);
        printf("PID -> (%d) Hello parent \n", pid);
    }

    return 0;
}
