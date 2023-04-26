#include "shell.h"

/**
 * execute_bin_ls - handle /bin/ls
 * @arr_of_words: arr containing commands
 * Return: void
*/
void execute_bin_ls(char **arr_of_words)
{
	pid_t pid;
	int curr_status;

	pid = fork();
	if (pid == 0)
	{
		exec_cmd_with_execve("/bin/ls", arr_of_words);
		perror("Error executing command\n");
		exit(100);
	}
	else if (pid < 0)
	{
		perror("Error forking");
		return;
	}
	else
		waitpid(pid, &curr_status, 0);
}



/**
 * execute_by_forking - executes a command using the fork-exec
 * @arr_of_words: arr containing commands
 * @sh_name: program name
 * Return: void
*/

void execute_by_forking(char **arr_of_words, char *sh_name)
{
	char *cmd = NULL, *cmd_to_exec = NULL;
	pid_t pid;
	int curr_status;

	if (arr_of_words)
	{
		cmd = arr_of_words[0];
		if (my_strcmp(cmd, "/bin/ls") == 0)
		{
			execute_bin_ls(arr_of_words);
			return;
		}
		if (handle_various_cmds(arr_of_words) == 1)
			return;
		cmd_to_exec = get_full_path(cmd);

		if (!cmd_to_exec)
		{
			if (!is_valid_word(cmd))
				p_the_err(sh_name, NULL, "No such file or directory\n");
			else
				p_the_err(sh_name, cmd, "not found\n");
			return;
		}

		pid = fork();
		if (pid == 0)
			exec_cmd_with_execve(cmd_to_exec, arr_of_words);
		else if (pid < 0)
		{
			perror("Error forking");
			return;
		}
		else
			wait_kid_process(pid, &curr_status);
	}
	free(cmd_to_exec);
}
