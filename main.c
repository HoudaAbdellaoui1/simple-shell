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
    char **command = NULL; 
    int status = 0;
    (void) ac;

    // Infinite loop
    while (1)
    {
        line = read_line();
        // reach EOF / ctrl+D behavior
        if (line == NULL)
        {
            // If program reaches end of file, print new line after ctrl + D
            // If we're on terminal
            if( isatty(STDIN_FILENO)==1)
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        command = splitter(line);
        if(!command)
            continue;
        status = _execute(command, argv);
    }
}
