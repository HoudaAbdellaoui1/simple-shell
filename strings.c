#include "shell.h"

char *_duplicate(const char *str)
{
    char *pointer;
    int i = 0, len = 0;

    if (str == NULL)
        return (NULL);
    while (*str != '\0')
    {
        len++;
        str++;
    }
    str = str - len;
    pointer = malloc(sizeof(char) * (len + 1));
    if (pointer == NULL)
        return (NULL);
    for (i = 0; i <= len; i++)
        pointer[i] = str[i];
    return (pointer);
}
int _compare(char *s1, char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}
int _length(char *s)
{
    int len = 0;

    while (s[len])
        len++;

    return (len);
}
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

char *_copy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *_itoa(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
        buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    reverse_string(buffer, i);

    return (_duplicate(buffer));
}

void reverse_string(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}
