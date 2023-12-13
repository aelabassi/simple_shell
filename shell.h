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
#define PATHDELIM "="
#define PATHENV "PATH"
#define PATHSEP ":"
extern char **environ;

char *_itoa(int n);
void _perror(char *name, char *cmd, int idx);
void _reverse_str(char *str, int len);
char *_readprompt(void);
char **tokensizer(char *str);
char **_tokenize(char *line);
void _free2D(char **arr);
int _executecmd(char **cmd, char **argv, int idx);
char *_getenv(char *env_var);
char *_getpath(char *cmd);
int _isunixcmd(char *cmd);
int _is_positive_status(const char *c);
void _builitin_cmd(char *cmds[]);
void handle_unixcmd(char **cmd, char **argv, int *status, int idx);
void _exit_shell(char **cmd, char **argv, int *status, int idx);
void _print_env(char **cmd, int *status);


/**
 * struct Unix_builtin_t - builts in commands
 * @func: function pointer that initializes a flexible array
*/

typedef struct Unix_builtin_t
{
	void (*func)(char *arr[]);
} unix_t;


#endif
