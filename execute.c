#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

int _execute(char **command, char **argv, int idx)
{
    pid_t child;
    int status;
    char *full_command;

    full_command = _getpath(command[0]);
    if (!full_command)
    {
        printerror(argv[0], command[0], idx)
            freearray2D(command);
        return (127);
    }
    child = fork();
    if (child == 0)
    {
        if (execve(full_command, command, environ) == -1)
        {
            free(full_command);
            full_command = NULL;
            freearray2D(command);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free(full_command);
        full_command = NULL;
        freearray2D(command);
    }
    return (WEXITSTATUS(status));
}
