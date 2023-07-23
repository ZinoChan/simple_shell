#include "shell.h"

/**
 * handle_various_cmds - handle env, setenv, unsetenv cmds
 * @arr_of_words: the cmds provided
 * @sh_name: program name
 * @cnt: cmonad count
 * @n: ------------------
 * @user_prompt: _______________
 * Return: 1 if one of the cmd is found or 0
*/

int handle_various_cmds(char **arr_of_words, char *user_prompt,
char *sh_name, int cnt, int n)
{
	char *cmd = arr_of_words[0];
	int cmd_was_handled = 0;
	(void)sh_name, (void)cnt, (void)n, (void)user_prompt;

	if (my_strcmp(cmd, "env") == 0)
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
