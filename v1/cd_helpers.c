#include "shell.h"

/**
 * env_vars - Gets the value of an environment variable.
 * @env_name: The name of the environment variable.
 * @env_pointer: Pointer to the environment variables array.
 *
 * Return: The value of the environment variable.
 */
char *env_vars(const char *env_name, char **env_pointer)
{
	char **the_env;

	for (the_env = env_pointer; *the_env != NULL; the_env++)
	{
		if (strncmp(env_name, *the_env, get_strlen(env_name)) == 0
				&& (*the_env)[get_strlen(env_name)] == '=')
		{
			return (*the_env + get_strlen(env_name) + 1);
		}
	}
	return (NULL);
}

/**
 * isError - Prints an error message.
 * @msg: The error message to print.
 */
void isError(const char *msg)
{
	printf("cd: %s\n", msg);
}

/**
 * get_dir - Gets the directory to change to.
 * @initial_path: The initial path passed to cd.
 *
 * Return: The directory to change to.
 */
char *get_dir(const char *initial_path)
{
	if (initial_path == NULL)
		return (env_vars("HOME", environ));
	else if (my_strcmp(initial_path, "-") == 0)
		return (env_vars("the_old_pwd", environ));
	else
		return ((char *)initial_path);
}

/**
 * handle_cwd - Gets the current working directory.
 *
 * Return: The current working directory.
 */
char *handle_cwd()
{
	char *the_cwd;

	the_cwd = getcwd(NULL, 0);
	if (the_cwd == NULL)
		perror("cd");
	return (the_cwd);
}

/**
 * switch_current_directory - Changes the current working directory.
 * @directory: The directory to change to.
 */
void switch_current_directory(const char *directory)
{
	if (chdir(directory) < 0)
		perror("cd");
}

