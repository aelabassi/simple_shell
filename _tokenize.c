#include "shell.h"

/**
 * _tokenize - split the user commands into tokens
 * @line: pointer to char, the command the user entered
 * Return: double pointer to char, array of tokens
*/

char **_tokenize(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	if (!line)
		return (NULL);
	token = strtok(line, DELIMITER);
	while (token)
	{
		i++;
		tokens = realloc(tokens, i * sizeof(char *));
		if (!tokens)
			return (NULL);
		tokens[i - 1] = token;
		token = strtok(NULL, DELIMITER);
	}
	tokens[i] = NULL;
	return (tokens);
}
