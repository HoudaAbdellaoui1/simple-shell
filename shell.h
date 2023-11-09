#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

char *read_line(void);
char **splitter(char *line);

char *_duplicate(const char *str);
int _compare(char *s1, char *s2);
char *_copy(char *dest, char *src);
char *_concat(char *dest, char *src);
int _length(char *s);

#endif
