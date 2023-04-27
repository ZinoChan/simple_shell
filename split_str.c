#include "shell.h"

/**
 * split_string - splits a string into an array of words
 * @str: the str to be splited
 * @str_separator: the delimeter
 * @num_of_words: number of words in the str
 * Return: the array of string or NULL
*/

char **split_string(char *str, const char *str_separator, int *num_of_words)
{
	char *str_copy = NULL, *word = NULL, **arr_of_words = NULL;
	int i;
	/*checks if str, str_separator, and num_of_words are valid pointers*/
	if (!str || !str_separator || !num_of_words)
		return (NULL);

	str_copy = malloc(sizeof(char) * get_strlen(str) + 1);
	if (str_copy == NULL)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	my_strcpy(str_copy, str);

	*num_of_words = 0;
	word = strtok(str_copy, str_separator);
	while (word != NULL)
	{
		(*num_of_words)++;
		word = strtok(NULL, str_separator);
	}
	arr_of_words = malloc(sizeof(char *) * (*num_of_words + 1));
	if (arr_of_words == NULL)
	{
		perror("Allocation Failed !");
		free(str_copy);
		return (NULL);
	}
	word = strtok(str_copy, str_separator);
	for (i = 0; word != NULL; i++)
	{
		arr_of_words[i] = malloc(sizeof(char) * get_strlen(word) + 1);
		if (arr_of_words[i] == NULL)
		{
			perror("Allocation Failed !");
			free_words(arr_of_words, i);
			free(str_copy);
			return (NULL);
		}
		my_strcpy(arr_of_words[i], word);
		word = strtok(NULL, str_separator);
	}

	arr_of_words[i] = NULL;
	free(str_copy);
	return (arr_of_words);
}
