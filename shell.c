#include "shell.h"

/**
 * main - Entry point for shell.
 *@argc: arg number
 * @argv: argumens
 * Return: Always returns 0.
 */


int main(int argc, char **argv)
{
	char *input_holder = NULL;
	(void)argv;

	if (argc == 1)
	{
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
	}
	else
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
