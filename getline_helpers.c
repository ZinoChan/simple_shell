#include "shell.h"


int read_from_input(char *char_to_read)
{
	ssize_t start = read(STDIN_FILENO, char_to_read, 1);

	if (start == -1)
		return 0;
	if (start == 0)
	{
		if (char_to_read != NULL)
			char_to_read[0] = '\0';
		return 0;
	}
	return 1;
}

void *my_realloc(void* old_ptr, size_t size)
{
	void* new_ptr;

    if (size == 0) {
        free(old_ptr);
        return NULL;
    }

    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return (NULL);

    if (old_ptr != NULL) {
        my_memcpy(new_ptr, old_ptr, size);
        free(old_ptr);
    }

    return (new_ptr);
}

void update_buff(char **buff_ptr, size_t *buff_size, char *buffer, size_t idx)
{
	if (*buff_ptr == NULL || *buff_size < idx)
	{
		*buff_size = (idx > STORAGE_SIZE) ? idx : STORAGE_SIZE;
		*buff_ptr = buffer;
	}
	else
	{
		my_strcpy(*buff_ptr, buffer);
		free(buffer);
	}
}

