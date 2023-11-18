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

extern char **environ;

char *
read_line(void);
char **splitter(char *line);
int _execute(char **command, char **argv, int idx);
char *_getenv(char *variable);
char *_getpath(char *command);
int is_builtin(char *command);
void handle_builtin(char **command, char**argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);

char *_duplicate(const char *str);
int _compare(char *s1, char *s2);
char *_copy(char *dest, char *src);
char *_concat(char *dest, char *src);
int _length(char *s);
void freearray2D(char **arr);
char *_itoa(int n);
void printerror(char *name, char *command, int id);
void reverse_string(char *str, int len);
int is_positive(char *str);
int _atoi(char *str);

#endif
