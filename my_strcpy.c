#include "shell.h"

/**
 * my_strcpy - copies a src to dest
 * @dest: destination str
 * @src: the original str
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
