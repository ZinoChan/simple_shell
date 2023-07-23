#include "shell.h"

/**
 * my_strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: A pointer to the destination string
 */
char *my_strcat(char *dest, const char *src)
{
	size_t dest_len = get_strlen(dest);

	my_strcpy(dest + dest_len, src);

	return (dest);
}

