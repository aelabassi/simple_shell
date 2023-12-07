#include "shell.h"

/**
 * _executecmd - executes shell commands
 * @cmd: commands, formatted into tokens
 * @argv: argument passed to the command
 * Return: status in which the execute exit with
*/

int _executecmd(char **cmd, char **argv)
{
	pid_t child_process;
	int status;

	child_process = fork();
	if (child_process == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			_free2D(cmd);
			perror(argv[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}

	return (WEXITSTATUS(status));
}
