#include "shell.h"

/**
 * my_strcmp - Compares two strings.
 *
 * @first: The first string to be compared.
 * @second: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero
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
