#include "shell.h"

/**
 * _is_positive - checks if the entered char
 * is between 0 and 9 strict
 * @c: char
 * Return: boolean: 1 if pos, and 0 otherwise
*/
int _is_positive(const char *c)
{
	int i;

	if (!c)
		return (0);
	for (i = 0; c[i]; i++)
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _itoa - convert an int to char
 * @n: int
 * Return: char
*/
char *_itoa(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	reverse_str(buff, i);
	return (strdup(buff));

}

/**
 * reverse_str - reverses a string
 * @str: string to reverse
 * @len: the length of the string
*/
void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * exit_shell - handle the exit command
 * @cmd: command entered
 * @argv: arguments of exit
 * @status: status of the exit
 * @idx: index of the command in the shell
*/
void exit_shell(char **cmd, char **argv, int *status, int idx)
	{
		int exit_value = (*status);
		char *index, mssg[] = ": exit: Illegal number: ";

		if (cmd[1])
		{
			if (_is_positive(cmd[1]))
			{
				exit_value = atoi(cmd[1]);
			}
			else
			{
				index = _itoa(idx);
				write(STDERR_FILENO, argv[0], strlen(argv[0]));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, index, strlen(index));
				write(STDERR_FILENO, mssg, strlen(mssg));
				write(STDERR_FILENO, cmd[1], strlen(cmd[1]));
				write(STDERR_FILENO, "\n", 1);

				free(index);
				free2D(cmd);
				*status = 2;
				return;
			}
		}

		free2D(cmd);
		exit(exit_value);
	}

/**
 * print_env - print the env variable
 * @cmd: the command entered
 * @status: status after typing a command
*/
void print_env(char **cmd, int *status)
{
		int i;

		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free2D(cmd);
		*status = 0;
}
