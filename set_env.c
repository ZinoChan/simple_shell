#include "shell.h"

/**
 * my_setenv - Set the value of an environment variable.
 *
 * @env_name: The name of the environment variable.
 * @env_value: The value to set the environment variable to.
 * @env_overwrite_val: A flag that determines whether to overwrite the
 *                     environment variable if it already exists.
 *
 * Return: 0 on success, -1 on failure.
 */
int my_setenv(const char *env_name, const char *env_value, int env_overwrite_val)
{
	int final_result;

	if (!env_name || env_name[0] == '\0')
	{
		perror("setenv: invalid variable name\n");
		return (-1);
	}

	if (!env_value)
		env_value = "";

	final_result = setenv(env_name, env_value, env_overwrite_val);

	if (final_result < 0)
		perror("setenv: failed to set env\n");

	return (final_result);
}
