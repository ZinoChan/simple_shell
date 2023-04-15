#include "shell.h"

/**
 * my_unsetenv - Unset an environment variable.
 *
 * @env_name: The name of the environment variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */
int my_unsetenv(const char *env_name)
{
	int final_result;

	if (!env_name || env_name[0] == '\0')
	{
		perror("unsetenv: invalid env name\n");
		return (-1);
	}

	final_result = unsetenv(env_name);

	if (final_result < 0)
		perror("unsetenv: failed to unset env\n");

	return (final_result);
}
