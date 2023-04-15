#include "shell.h"

/**
 * get_dir_path - Concatenates a directory path and a command name
 * @path: The directory path
 * @cmd: The command name
 *
 * Return: new string with the concatenated path and command name
 */
char *get_dir_path(const char *path, const char *cmd)
{
	char *dir_path = malloc(get_strlen(path) + get_strlen(cmd) + 2);

	if (!dir_path)
		return (NULL);

	my_strcpy(dir_path, path);
	my_strcat(dir_path, "/");
	my_strcat(dir_path, cmd);

	return (dir_path);
}
