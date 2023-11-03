#include "shell.h"

/**
 * main - Shell main function 
 * @ac: Count of arguments 
 * @av: Arguments
 * Return: 0
 * **/

int main(int ac, char **argv)
{
    char *line = NULL; 
    // char *command = NULL; 
    int status = 0;
    (void) ac;

    // Infinite loop
    while (1)
    {
        line = read_line();

        // reach EOF / ctrl+D behavior
        if (line == NULL)
        {
            // Return new line after ctrl + D
            write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        return (status);
        printf("%s", line);
        free(line);

        // command = splitter(line);

        // status = _execute(command, argv);
    }

}