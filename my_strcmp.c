#include "shell.h"

/**
 * my_strcmp - Compares two strings.
 * @first: The first string
 * @second: The second string
 * Return: An integer;
 */
int my_strcmp(const char *first, const char *second)
{
	while (*first == *second && *first != '\0')
	{
		first++;
		second++;
	}

	return ((int)(*first) - (int)(*second));
}
