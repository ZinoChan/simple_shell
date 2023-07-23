#include "shell.h"

/**
 * get_full_path - search for the full path of a command
 * @cmd: the command
 * Return: full directory path or NULL
*/

char *get_full_path(const char *cmd)
{
	char *copy_of_path, *dir_path, *token_of_path;

	copy_of_path = get_path_copy();
	if (!copy_of_path)
		return (NULL);

	dir_path = NULL;
	token_of_path = strtok(copy_of_path, ":");

	while (token_of_path != NULL)
	{
		dir_path = get_dir_path(token_of_path, cmd);
		if (!dir_path)
			break;

		if (file_exists(dir_path) == 1)
		{
			free(copy_of_path);
			return (dir_path);
		}
		else
		{
			free(dir_path);
			dir_path = NULL;
			token_of_path = strtok(NULL, ":");
		}
	}

	free(copy_of_path);

	if (file_exists(cmd) == 1)
		return ((char *) cmd);

	return (dir_path);
}
