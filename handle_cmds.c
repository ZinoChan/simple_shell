#include "shell.h"

/**
 * handle_various_cmds - handle env, setenv, unsetenv cmds
 * @arr_of_words: the cmds provided
 * Return: 1 if one of the cmd is found or 0
*/

int handle_various_cmds(char **arr_of_words)
{
	char *cmd = arr_of_words[0];
	int exit_status, cmd_was_handled = 0;

	if (my_strcmp(cmd, "exit") == 0)
	{
		exit_status = 0;
		if (arr_of_words[1])
			exit_status = my_atoi(arr_of_words[1]);
		exit(exit_status);
	}
	else if (my_strcmp(cmd, "env") == 0)
	{
		handle_the_env();
		cmd_was_handled = 1;
	}
	else if (my_strcmp(cmd, "setenv") == 0)
	{
		if (arr_of_words[1] && arr_of_words[2])
			my_setenv(arr_of_words[1], arr_of_words[2], 1);
		else
			perror("Usage: setenv VARIABLE VALUE\n");
		cmd_was_handled = 1;
	}
	else if (my_strcmp(cmd, "unsetenv") == 0)
	{
		if (arr_of_words[1])
			my_unsetenv(arr_of_words[1]);
		else
			perror("Usage: unsetenv VARIABLE\n");
		cmd_was_handled = 1;
	}
	return (cmd_was_handled);
}
