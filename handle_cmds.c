#include "shell.h"

/**
 * handle_various_cmds - handle env, setenv, unsetenv cmds
 * @arr_of_words: the cmds provided
 * @user_prompt: the prompt displayed to the user
 * @sh_name: the name of the shell program
 * @cnt: the current command number in the shell session
 * @n: the total number of commands in the shell session
 * Return: 1 if one of the cmd is found or 0
*/

int handle_various_cmds(char **arr_of_words, char *user_prompt, char *sh_name,
int cnt, int n)
{
	char *cmd = arr_of_words[0];
	int cmd_was_handled = 0;

	if (my_strcmp(cmd, "exit") == 0)
		handle_exit_with_status(arr_of_words, user_prompt, sh_name, cnt, n);

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
	else if (my_strcmp(cmd, "cd") == 0)
	{
		my_cd(arr_of_words);
		cmd_was_handled = 1;
	}
	return (cmd_was_handled);
}
