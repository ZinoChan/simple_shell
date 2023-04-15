#include "shell.h"

/**
 * handle_the_env - Prints the env variables.
 * Return: void
 */
void handle_the_env(void)
{
	extern char **environ;
	char **env_pointer = environ;

	while (*env_pointer)
	{
		printf("%s\n", *env_pointer);
		env_pointer++;
	}
}
