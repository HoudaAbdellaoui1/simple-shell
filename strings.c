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
int _compare(char *s1, char *s2)
{
    while (*s1 && *s1 == *s2) { ++s1; ++s2; }
    return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}
// length calculator
int _length(char *s)
{
    int len = 0;

    while(s[len])
        len++;
    return (len);
}
// // concatenator
char *_concat(char *dest, char *src)
{
    char *p = dest;

    while (*p)
        p++;

    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return (dest);
}

// // copier
char *_copy(char *dest, char *src)
{
    int i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
