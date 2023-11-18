#include "shell.h"

char **splitter(char *line)
{
    char *token = NULL, delim[] = " \t\n", *tmp = NULL;
    char **command = NULL;
    int counter = 0, i = 0;

    if (!line)
        return (NULL);
    tmp = _duplicate(line);
    token = strtok(tmp, delim);
    if (token == NULL)
    {
        free(tmp);
        free(line);
        return (NULL);
    }
    while (token)
    {
        counter++;
        token = strtok(NULL, delim);
    }
    free(tmp), tmp = NULL;
    command = malloc(sizeof(char *) * (counter + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token = strtok(line, delim);
    while (token)
    {
        command[i] = _duplicate(token);
        token = strtok(NULL, delim);
        i++;
    }
    free(line);
    command[i] = NULL;
    return (command);
}
