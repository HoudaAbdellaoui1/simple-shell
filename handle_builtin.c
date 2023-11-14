#include "shell.h"

int is_builtin(char *command)
{
    char *builtins[] = {
        "exit", "env", "setenv", "cd", NULL
    };
    int i = 0;

    for (i = 0; builtins[i]; i++)
    {
        if(_compare(command, builtins[i]) == 0)
            return (1);
    }
    return (0);
}

void handle_builtin(char **command, char**argv, int *status, int idx)
{
    if(_compare(command[0], "exit") == 0)
        exit_shell(command, argv, status, idx);
    else if(_compare(command[0], "env") == 0)
        print_env(command, status);
}

void exit_shell(char **command, char **argv, int *status, int idx)
{
    int exit_status = (*status);
    char *index, message[] = ": exit: Illegal number: ";

    if(command[1])
    {
        if(is_positive(command[1]))
        {
            exit_status = _atoi(command[1]);
        }
        else
        {
            index = _itoa(idx);
            write(STDERR_FILENO, argv[0], _length(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, index, _length(index));
            write(STDERR_FILENO, message, _length(message));
            write(STDERR_FILENO, command[1], _length(command[1]));
            write(STDERR_FILENO, "\n", 1);
            free(index);
            freearray2D(command);
            (*status) = 2;
            return;
        }
    }
    freearray2D(command);
    exit(exit_status);
}

void print_env(char **command, int *status)
{
    int i = 0;
    (void) status;

    for(i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _length(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearray2D(command);
    (*status) = 0;
}
