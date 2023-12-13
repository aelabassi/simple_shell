#include "shell.h"
/**
 * _isunixcmd - if the command a built in
 * @cmd: command entered
 * Return: 1 if it is, 0 otherwise.
*/
int _isunixcmd(char *cmd)
{
	int i;
	char *builtins_cmd[10] = {"exit", "env", "setenv", NULL};

	for (i = 0; builtins_cmd[i]; i++)
	{
		if (strcmp(cmd, builtins_cmd[i]) == 0)
		{
			return (1);
		}
	}

	return (0);

}

/**
 * handle_unixcmd - handles exit and env
 * @cmd: array of commands
 * @argv: arguments passed to command
 * @status: status of exit, or undefined command
 * @idx: display index
*/

void handle_unixcmd(char **cmd, char **argv, int *status, int idx)
{

	if (strcmp(cmd[0], "exit") == 0)
	{
		_exit_shell(cmd, argv, status, idx);
	}
	else if (strcmp(cmd[0], "env") == 0)
	{
		_print_env(cmd, status);
	}


}
