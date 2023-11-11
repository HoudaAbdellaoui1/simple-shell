#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    // declare a 2D-array : command
    char *cmd[] = {"/bin/ls", "-l", "/usr/", NULL};
    pid_t fork_value;
    int status;

    printf("Before fork\n");
    fork_value = fork();
    if (fork_value == 0)
    {
        // Execute the commands contained in command using execve()
        if (execve(cmd[0], cmd, NULL) == -1)
        {
            perror("Error: ");
        }
    }
    else
    {
        // Use the waitpid() function to run the child process before the parent process
        waitpid(fork_value, &status, 0);
        printf("Child has finished\n");
    }
    // execve() exits once it is done
    // In order to prevent this program exiting, we used fork()
    // fork() creates a child process (identical to the parent) to be executed inside another program
    // If return value of the fork() function is 0 => running process is the child
    // else: running process is the parent
    // We will run execve() inside a child process
    return (0);
}
