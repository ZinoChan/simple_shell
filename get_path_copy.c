#include "shell.h"

/**
 * get_path_copy - Gets a copy of the PATH env var
 * Return: A new allocated string containing a copy of the PATH variable,
 * or NULL.
 */
char *get_path_copy()
{
	char *path = getenv("PATH");
	char *path_copy;

	if (!path)
		return (NULL);

	path_copy = my_strdup(path);
	if (!path_copy)
		return (NULL);

	return (path_copy);
}
