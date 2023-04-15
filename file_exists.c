#include "shell.h"

/**
 * file_exists - Checks if a file exists
 * @path: The path of the file to check
 * Return: 1 if the file exists, 0 otherwise
 */
int file_exists(const char *path)
{
	struct stat buffer;

	if (stat(path, &buffer) != 0)
		return (0);
	return (1);
}
