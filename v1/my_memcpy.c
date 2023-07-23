#include "shell.h"

/**
 * my_memcpy - copies mem like c memcpy
 * @destination: the ...
 * @source: the ...
 * @num_of_bytes: the ...
 * Return: void
*/
void *my_memcpy(void *destination, const void *source,
size_t num_of_bytes)
{
	unsigned char *dest = destination;
	const unsigned char *src = source;
	size_t idx;

	while (idx < num_of_bytes)
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (destination);
}
