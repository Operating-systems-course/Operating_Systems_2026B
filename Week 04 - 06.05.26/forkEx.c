#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    puts("------------------------");
    pid = fork();
    
    if (pid < 0)
        return 1;
    else if (pid == 0)
    {
        printf("PID -> (%d) Hello child \n", pid);
        execvp(argv[1], argv+1);

        return 1;
    }
    else
    {
        wait(NULL);
        printf("PID -> (%d) Hello parent \n", pid);
    }

    return 0;
}
