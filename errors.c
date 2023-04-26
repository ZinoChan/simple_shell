#include "shell.h"


/**
 * p_the_err - errrorrorrooror
 * @sh_name: naaaaaaame
 * @cmd: cmmmmmmmd
 * @msg: msssssg
 * @cnt: cmonad count
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
