#include "shell.h"

/**
 * main - Entry point for shell.
 *
 * Return: Always returns 0.
 */


int main(void)
{
	char *input_holder = NULL;
	const char *str_seperator = " ";
	int num_of_words = 0;
	char **arr_of_words = NULL;

	while (1)
	{
		input_holder = read_input();
		if (input_holder == NULL)
		{
			printf("\n");
			return (-1);
		}
		arr_of_words = split_string(input_holder, str_seperator, &num_of_words);
		execute_by_forking(arr_of_words);
	}
	free_words(arr_of_words, num_of_words);
	free(input_holder);
	input_holder = NULL;
	return (0);
}
