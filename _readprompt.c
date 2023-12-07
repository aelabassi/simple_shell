#include "shell.h"

/**
 * _readprompt - reads user's input
 * Return: pointer to char, the string the user entered
*/
char *_readprompt(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	read = getline(&buffer, &buffer_size, stdin);
	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
