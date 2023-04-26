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
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("$ ");
			input_holder = read_input();
			if (input_holder == NULL)
			{
				printf("\n");
				return (-1);
			}
			exec_multi_cmds(input_holder, argv[0]);
			free(input_holder);
			input_holder = NULL;
		}
	}
	else
	{
		while ((input_holder = read_input()) != NULL)
		{
			exec_multi_cmds(input_holder, argv[0]);
			free(input_holder);
		}

		input_holder = NULL;
	}

	return (0);
}

