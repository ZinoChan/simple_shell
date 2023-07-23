#include "shell.h"

/**
 * handle_exit_with_status - Handles exit built-in command.
 * @arr_of_words: commands
 * @user_prompt: user input.
 * @sh_name: program name
 * @cntr: conter of commands
 * @n: number of commands
 * Return: void.
 */
void handle_exit_with_status(char **arr_of_words, char *user_prompt,
char *sh_name, int cntr, int n)
{
	int ex_stat, i = 0;

	if (arr_of_words[1] == NULL)
	{
		free(user_prompt);
		free_words(arr_of_words, n);
		exit(EXIT_SUCCESS);
	}

	while (arr_of_words[1][i])
	{
		if (my_isdig(arr_of_words[1][i++]) == 0)
		{
			ex_err(arr_of_words, cntr, sh_name);
			break;
		}
		else
		{
			ex_stat = my_atoi(arr_of_words[1]);
			free(user_prompt);
			free_words(arr_of_words, n);
			exit(ex_stat);
		}
	}

}
