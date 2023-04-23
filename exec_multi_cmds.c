#include "shell.h"

/**
 * exec_multi_cmds - Execute multiple commands separated by semicolons
 * @user_prompt: The user input string containing the commands
 */
void exec_multi_cmds(char *user_prompt)
{
	int num_of_cmds, num_of_words, i;
	char **arr_of_cmds, **arr_of_words;

	arr_of_cmds = split_string(user_prompt, ";", &num_of_cmds);
	if (arr_of_cmds == NULL)
	{
		printf("Error splitting user input\n");
		return;
	}

	for (i = 0; i < num_of_cmds; i++)
	{
		arr_of_words = split_string(arr_of_cmds[i], " \t\r\n", &num_of_words);
		if (arr_of_words == NULL)
		{
			perror("Error splitting command string\n");
			continue;
		}

		execute_by_forking(arr_of_words);
		free_words(arr_of_words, num_of_words);
	}

	free_words(arr_of_cmds, num_of_cmds);
}
