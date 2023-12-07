#include "shell.h"

/**
 * _free2D - deallocate a 2d array, basically a chaine of strings
 * @a: double pointer char--which is an array of strings
*/
void _free2D(char **a)
{
	int i;

	for (i = 0; a[i]; i++)
	{
		free(a[i]);
	}

	free(a);
}
