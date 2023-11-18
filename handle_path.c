#include "shell.h"

char *_getpath(char *command)
{
    char *path_env, *full_cmd, *dir;
    struct stat st;
    int i = 0;

    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return (_duplicate(command));
            return (NULL);
        }
    }
    path_env = _getenv("PATH");
    if (!path_env)
        return (NULL);
    dir = strtok(path_env, ":");
    while (dir)
    {
        full_cmd = malloc(_length(dir) * _length(command) + 2);
        if (full_cmd)
        {
            _copy(full_cmd, dir);
            _concat(full_cmd, "/");
            _concat(full_cmd, command);
            if (stat(full_cmd, &st) == 0)
            {
                free(path_env);
                return (full_cmd);
            }
            free(full_cmd), full_cmd = NULL;
            dir = strtok(NULL, ":");
        }
    }
    free(path_env);
    return (NULL);
}
