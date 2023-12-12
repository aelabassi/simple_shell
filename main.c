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
	int status = 0, idx;
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
		commands = _tokenize(line);
		if (!commands)
			continue;
		for (idx = 0; commands[idx]; idx++)
		{
			printf("%s\n", commands[idx]);
		}
		_free2D(commands);
	}



	return (0);
}
