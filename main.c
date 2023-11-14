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
    int status = 0, idx = 0;
    (void)ac;

    while (1)
    {
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO) == 1)
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        idx++;
        command = splitter(line);
        if (!command)
            continue;
        status = _execute(command, argv, idx);
    }
}
