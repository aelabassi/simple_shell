#include "shell.h"

/**
 * _getenv - get the environments variables
 * @env_var: env variable
 * Return: env variable
*/

char *_getenv(char *env_var)
{
	char *path_name, *path,  *env, *temp;
	int i = 0;

	while (environ[i])
	{
		temp = strdup(environ[i]);
		path_name = strtok(temp, PATHDELIM);
		if (strcmp(path_name, env_var) == 0)
		{
			path = strtok(NULL, "\n");
			env = strdup(path);
			free(temp);
			return (env);
		}
		i++;
		free(temp), temp = NULL;
	}

	return (NULL);
}

/**
 * _getpath - checks if a path is within PATH env
 * @cmd: typed command
 * Return: path
*/
char *_getpath(char *cmd)
{
	char *path_env, *complete_cmd, *cmd_path;
	struct stat st;
	int i = 0;

	while (cmd[i])
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
		return (NULL);
		i++;
	}
	path_env = _getenv(PATHENV);
	if (!path_env)
		return (NULL);
	cmd_path = strtok(path_env, PATHSEP);
	while (cmd_path)
	{
		complete_cmd = malloc(strlen(cmd_path) + 2 * strlen(cmd));
		if (complete_cmd)
		{
			strcpy(complete_cmd, cmd_path);
			strcat(complete_cmd, "/");
			strcat(complete_cmd, cmd);
			if (stat(complete_cmd, &st) == 0)
			{
				free(path_env);
				return (complete_cmd);
			}
			free(complete_cmd), complete_cmd = NULL;
			cmd_path = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);

}
