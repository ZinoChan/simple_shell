#include "shell.h"


/**
 * p_the_err - prints error message to standard error
 * @cnt: command count
 * @sh_name: shell name
 * @cmd: command
 * @msg: error message
 * Return: void
*/
void p_the_err(char *cnt, char *sh_name, char *cmd, char *msg)
{
	write(STDERR_FILENO, sh_name, get_strlen(sh_name));
	if (cmd != NULL)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cnt, get_strlen(cnt));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, get_strlen(cmd));
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, get_strlen(msg));
}

/**
 * ex_err - prints error message for an invalid argument
 * @arr_of_words: array of command line arguments
 * @cntr: command count
 * @sh_name: shell name
 * Return: void
 */
void ex_err(char **arr_of_words, int cntr, char *sh_name)
{
	char *err_code = intToString(cntr);

	write(STDOUT_FILENO, sh_name, get_strlen(sh_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err_code, get_strlen(err_code));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, arr_of_words[0], get_strlen(arr_of_words[0]));
	write(STDOUT_FILENO, ": Illegal number: ", 19);
	write(STDOUT_FILENO, arr_of_words[1], get_strlen(arr_of_words[1]));
	write(STDOUT_FILENO, "\n", 2);

	free(err_code);
}
