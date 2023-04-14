#include "shell.h"

/**
 * execute_cmd_with_execve - the name explains it
 * @cmd: the command to execute
 * @arr_of_words: arr of commands
 * Return: void
*/

void execute_cmd_with_execve(char *cmd, char **arr_of_words)
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
