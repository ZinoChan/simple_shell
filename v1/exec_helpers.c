#include "shell.h"

/**
 * exec_cmd_with_execve - the name explains it
 * @cmd: the command to execute
 * @arr_of_words: arr of commands
 * Return: void
*/

void exec_cmd_with_execve(char *cmd, char **arr_of_words)
{
	if (execve(cmd, arr_of_words, NULL) == -1)
	{
		perror("Error executing command");
		return;
	}
}


/**
 * wait_kid_process - wait child process to end
 * @pid: process id
 * @status: status of process
 * Return: void
*/

void wait_kid_process(pid_t pid, int *status)
{
	if (waitpid(pid, status, 0) == -1)
	{
		perror("Error while waiting for child process");
		return;
	}
}
/**
 * is_valid_word - check if workd valid
 * @str: word
 * Return: 1 if valid 0 no
*/
int is_valid_word(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!isalnum(str[i]) && str[i] != '-' && str[i] != '_' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

