#include "shell.h"

char *_getenv(char *variable)
{
    int i = 0;
    char *tmp, *key, *value, *env;

    for (i = 0; environ[i]; i++)
    {
        tmp = _duplicate(environ[i]);
        key = strtok(tmp, "=");
        if (_compare(key, variable) == 0)
        {
            value = strtok(NULL, "\n");
            env = _duplicate(value);
            free(tmp);
            return (env);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
