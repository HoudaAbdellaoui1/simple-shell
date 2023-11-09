#include "shell.h"

char **splitter(char *line)
{
    char *token = NULL, delim[] = " \t\n", *tmp = NULL;
    char **command = NULL;
    int counter = 0, i = 0;

    if (!line)
        return (NULL);
    tmp = _duplicate(line);
    // Tokenize 'line'
    token = strtok(tmp, delim);
    if(token == NULL)
    {
        free(tmp);
        free(line);
        return (NULL);
    }
    while (token)
    {
        counter ++;
        token = strtok(NULL, delim);
    }
    free(tmp), tmp = NULL;
    // put the token is a 2D array 
    // in order to return the complete splitted line
    // We need to know the size of the 2D array
    // To do this, we'll tokenize the whole line and add a counter for the no of tokens
    // this counter will be used next to allocate memory for the  2D array
    // 
    command = malloc(sizeof(char *) * (counter + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    // do the same for line
    token = strtok(line, delim);
    while (token)
    {
        command[i] = _duplicate(token);
        token = strtok(NULL, delim);
        i++;
    }
    free(line);
    command[i] = NULL;
    // command is the 2D array containing all tokens
    return (command);
}
