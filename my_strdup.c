#include "shell.h"

/**
 * my_strdup - Duplicates a string
 * @s: The string
 * Return: new string pointer or NULL
 */
char *my_strdup(const char *s)
{
	size_t len = get_strlen(s), i;
	char *dup = malloc(len + 1);

	if (dup)
	{
		for (i = 0; i < len; i++)
			dup[i] = s[i];
		dup[len] = '\0';
	}

	return (dup);
}
