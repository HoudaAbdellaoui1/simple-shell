#include "shell.h"

// duplicator
char *_duplicate(const char *str)
{
    char *pointer;
    int i = 0, len = 0;

    if(str == NULL)
        return (NULL);
    while(*str != '\0')
    {
        len++;
        str++;
    }
    str = str - len;
    pointer = malloc(sizeof(char) * (len + 1));
    if(pointer == NULL)
        return (NULL);
    for (i = 0; i <= len; i++)
        pointer[i] = str[i];
    return(pointer);
}
// comparer
// int _compare(char *s1, char *s2)
// {
//     int cmp;

//     cmp = (int)*s1 - (int)*s2;

// }
// length calculator
// int _length(char *s){}
// // concatenator
// char *_concat(char *dest, char *src)
// {

// }

// // copier
// char *_copy(char *dest, char *src)
// {

// }
