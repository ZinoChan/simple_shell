#include "shell.h"

/**
 * main - Entry point for shell.
 *
 * Return: Always returns 0.
 */


int main(void)
{
	char *input_holder = NULL;

	while (1)
	{
		input_holder = read_input();
		if (input_holder == NULL)
		{
			printf("\n");
			return (-1);
		}
		exec_multi_cmds(input_holder);
		free(input_holder);
		input_holder = NULL;
	}

	return (0);
}
