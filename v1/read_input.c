#include "shell.h"

/**
 * read_input - Reads a line of input from stdin.
 * This function prompts the user to enter input, reads a line of input
 * from stdin using the getline() function, and returns a pointer to the
 * input string.
 * Return: A pointer to the input string, or NULL on error or empty line.
 */
char *read_input()
{
	char *input_holder = NULL;
	size_t alloc_size = 0;
	ssize_t total_read;

	fflush(stdout);
	total_read = getline(&input_holder, &alloc_size, stdin);

	if (total_read == -1)
	{
		free(input_holder);
		return (NULL);
	}
	if (total_read > 0 && input_holder[total_read - 1] == '\n')
	{
		input_holder[total_read - 1] = '\0';
	}
	return (input_holder);
}
