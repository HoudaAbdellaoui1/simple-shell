#include "shell.h"


char *read_line(void)
{
    char *line = 0;
    size_t len = 0;
    ssize_t n;
    
    // program needs to write this only if we are on standard terminal
    // To check this, we use isatty()
    if( isatty(STDIN_FILENO)==1)
        write(STDOUT_FILENO, "$ ",2);
    // Allocates memory for the line
    // Reads from online string (stdin in this case)
    // Returns how many characters were found 
    n = getline(&line, &len, stdin);

    if (n == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}
