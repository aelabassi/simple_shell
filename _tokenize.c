#include "shell.h"

/**
 * _tokenize - split the user commands into tokens
 * @line: pointer to char, the command the user entered
 * Return: double pointer to char, array of tokens
*/

char **_tokenize(char *line)
{
	char **tokens = NULL;
	char *token = NULL, *tmp_ = NULL;
	int i = 0, count = 0;

	if (!line)
		return (NULL);
	tmp_ = strdup(line);
	token = strtok(tmp_, DELIMITER);
	if (!token)
	{
		free(line), line = NULL;
		free(tmp_), tmp_ = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIMITER);
	}
	free(tmp_);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, DELIMITER);
	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}
	free(line), line = NULL;
	tokens[i] = NULL;
	return (tokens);
}
