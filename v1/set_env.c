#include "shell.h"

/**
 * my_setenv - Set the value of an environment variable.
 * @env_name: name of env var.
 * @env_value: The val to set the env var to.
 * @env_overwrite_val: flag
 * Return: 0 on success, or -1.
 */
int my_setenv(const char *env_name, const char *env_value,
			int env_overwrite_val)
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
