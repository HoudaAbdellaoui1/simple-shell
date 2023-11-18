#include "shell.h"

void freearray2D(char **arr)
{
    int i = 0;

    if (!arr)
        return;

    for (i = 0; arr[i]; i++)
        free(arr[i]), arr[i] = NULL;

    free(arr[i]), arr[i] = NULL;
}

void printerror(char *name, char *command, int id)
{
    char *index, message[] = " : not found\n";

    index = _itoa(id);

    write(STDERR_FILENO, name, _length(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _length(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, command, _length(command));
    write(STDERR_FILENO, message, _length(message));
}
