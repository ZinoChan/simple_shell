#include "shell.h"

/**
 * exec_multi_cmds - Execute multiple commands separated by semicolons
 * @user_prompt: The user input string containing the commands
 * @sh_name: program name
 * @cnt: cmonad count
 * Return: error code
 */
int exec_multi_cmds(char *user_prompt, char *sh_name, int cnt)
{
	int num_of_cmds, num_of_words, i, ex_code;
	char **arr_of_cmds, **arr_of_words;

	arr_of_cmds = split_string(user_prompt, ";", &num_of_cmds);
	if (arr_of_cmds == NULL)
	{
		printf("Error splitting user input\n");
		return (errno);
	}

	for (i = 0; i < num_of_cmds; i++)
	{
		arr_of_words = split_string(arr_of_cmds[i], " \t\r\n", &num_of_words);
		if (arr_of_words == NULL)
		{
			perror("Error splitting command string\n");
			continue;
		}
		if (my_strcmp(arr_of_words[0], "/bin/ls") == 0)
		{
			execute_bin_ls(arr_of_words);
			return (0);
		}
		if (my_strcmp(arr_of_words[0], "exit") == 0)
		{
			free_words(arr_of_cmds, num_of_cmds);
			handle_exit_with_status(arr_of_words, user_prompt,
			sh_name, cnt, num_of_words);
		}
		ex_code = execute_by_forking(arr_of_words, user_prompt, sh_name,
		cnt, num_of_words);
		free_words(arr_of_words, num_of_words);
	}

	free_words(arr_of_cmds, num_of_cmds);
	return (ex_code);
}
