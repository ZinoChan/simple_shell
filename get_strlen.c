#include "shell.h"

/**
 * get_strlen - get string length
 * @str: the string
 * Return: length
*/

size_t get_strlen(const char *str)
{
	size_t ans = 0;

	while (*str != '\0')
	{
		ans++;
		str++;
	}
	return (ans);
}
