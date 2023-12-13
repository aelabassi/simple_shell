#include "shell.h"

/**
 * main - runs the tests here
 * @argc: number of arguemnts passed to main: int
 * @argv: the arguments passed to main: array of strings
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *line = NULL, **commands = NULL;
	int status = 0, idx = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		line = _readprompt();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		commands = _tokenize(line);
		if (!commands)
			continue;
		if (_isunixcmd(commands[0]))
			handle_unixcmd(commands, argv, &status, idx);
		else
			status = _executecmd(commands, argv, idx);

		_free2D(commands);
	}



	return (0);
}
