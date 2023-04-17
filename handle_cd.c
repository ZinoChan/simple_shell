#include "shell.h"

/**
 * my_cd - handle cd command
 * @arr_of_words: the arr of words
 * Return: void
*/

void my_cd(char **arr_of_words)
{
	char *initial_directory = NULL, *the_old_pwd, *the_curr_pwd;

	initial_directory = get_dir(arr_of_words[1]);
	if (initial_directory == NULL)
	{
		isError("the directory is not found");
		return;
	}
	the_old_pwd = handle_cwd();
	if (the_old_pwd == NULL)
		return;
	if (my_setenv("the_old_pwd", the_old_pwd, 1) < 0)
	{
		free(the_old_pwd);
		return;
	}
	free(the_old_pwd);
	switch_current_directory(initial_directory);
	the_curr_pwd = handle_cwd();
	if (the_curr_pwd == NULL)
		return;
	if (my_setenv("PWD", the_curr_pwd, 1) < 0)
	{
		free(the_curr_pwd);
		return;
	}
	free(the_curr_pwd);
}
