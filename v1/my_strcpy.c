#include "shell.h"

/**
 * my_strcpy - copies a src to dest
 * @dest: dest str
 * @src: the string
 * Return: the copied string
*/

char *my_strcpy(char *dest, const char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}
