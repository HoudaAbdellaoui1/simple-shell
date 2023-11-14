#include "shell.h"

char *_getpath(char *command)
{
    char *path_env, *full_cmd, *dir;
    struct stat st;

    path_env = _getenv("PATH");
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
int main(int ac, char **argv)
{
    char *full_cmd;

    full_cmd = _getpath(av[1]);
    if (full_cmd)
        printf("%s\n", full_cmd);
    else
        printf("doesnt exist");
}
