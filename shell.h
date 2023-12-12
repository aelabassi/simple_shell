#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define DELIMITER " \t\n"
extern char **environ;

char *_itoa(int n);
void _perror(char *name, char *cmd, int idx);
void reverse_str(char *str, int len);
char *read_prompt(void);
char **tokensizer(char *str);
char **_tokenize(char *line);
void free2D(char **arr);
int _executecmd(char **cmd, char **argv, int idx);
char *_getenv(char *var);
char *_getpath(char *cmd);
int _isunixcmd(char *cmd);
int _is_positive(const char *c);
void handle_unixcmd(char **cmd, char **argv, int *status, int idx);
void exit_shell(char **cmd, char **argv, int *status, int idx);
void print_env(char **cmd, int *status);





#endif
