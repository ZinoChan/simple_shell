#include "shell.h"

/**
 * free_words - Frees a list of words.
 * @words: Pointer to an array of strings.
 * @num_of_words: Number of words in the array.
 * This function frees each individual string in the array using the
 * free() function and finally frees the array itself using free().
 */
void free_words(char **words, int num_of_words)
{
	int i;

	if (words == NULL)
		return;
	for (i = 0; i < num_of_words; i++)
	{
		if (words[i] != NULL)
		{
			free(words[i]);
			words[i] = NULL;
		}
	}
	free(words);
}
