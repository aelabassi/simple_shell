#include "shell.h"

/**
 * _executecmd - executes shell commands
 * @cmd: commands, formatted into tokens
 * @argv: argument passed to the command
 * @idx: display index
 * Return: status in which the execute exit with
*/

int _executecmd(char **cmd, char **argv, int idx)
{
	pid_t child;
	int status;
	char *fcmd;

	fcmd = _getpath(cmd[0]);
	if (!fcmd)
	{
		_perror(argv[0], cmd[0], idx);
		free2D(cmd);
		return (127);
	}


	child = fork();
	if (child == 0)
	{
		if (execve(fcmd, cmd, environ) == -1)
		{
			free(fcmd), fcmd = NULL;
			perror(argv[0]);
			free2D(cmd);
			exit(127);
		}

	}
	else
	{
		waitpid(child, &status, 0);
		free2D(cmd);
		free(fcmd), fcmd =  NULL;
	}

	return (WEXITSTATUS(status));
}

/**
 * _perror - displays an error message whenever
 * hsh enounters undefined commands
 * @name: name of the executable (hsh)
 * @cmd: the name of the command
 * @idx: index where the command executed
*/
void _perror(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, mssg, strlen(mssg));

	free(index);

}
