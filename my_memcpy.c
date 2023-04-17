#include "shell.h"

void* my_memcpy(void* destination, const void* source,
size_t num_of_bytes)
{
    unsigned char *dest = destination;
    const unsigned char *src = source;
	size_t idx;

    for (idx = 0; idx < num_of_bytes; idx++) {
        dest[idx] = src[idx];
    }
    return destination;
}
