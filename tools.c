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
