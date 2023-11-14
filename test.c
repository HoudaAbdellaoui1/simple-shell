#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *cmd[] = {"/bin/ls", "-l", "/usr/", NULL};
    pid_t fork_value;
    int status;

    printf("Before fork\n");
    fork_value = fork();
    if (fork_value == 0)
    {
        if (execve(cmd[0], cmd, NULL) == -1)
        {
            perror("Error: ");
        }
    }
    else
    {
        waitpid(fork_value, &status, 0);
        printf("Child has finished\n");
    }
    return (0);
}
