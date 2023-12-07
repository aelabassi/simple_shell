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

char *_readprompt(void);
char **_tokenize(char *line_);
void _free2D(char **a);
int _executecmd(char **cmd, char **argv);





#endif
