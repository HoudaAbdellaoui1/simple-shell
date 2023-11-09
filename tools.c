#include "shell.h"

void c(char **arr)
{
    int i = 0;

    if(!arr)
        return;

    for (i = 0; arr[i]; i++)
            free(arr[i]), arr[i]= NULL;

        free(arr[i]), arr[i]= NULL;
}
