#include "shell.h"


ssize_t my_getline(char **the_storage_ptr, size_t *size_of_storage,
FILE *read_stream)
{
	ssize_t line_length = 0, starting_input = 0;
	char *storage = NULL, curr_char;

	if (starting_input == 0)
		fflush(read_stream);
	else
		return (-1);

	storage = malloc(STORAGE_SIZE * sizeof(char));
	if (storage == NULL)
		return (-1);

	while (curr_char != '\n')
	{
		if (!read_from_input(&curr_char))
		{
			free(storage);
			return (-1);
		}

		if (starting_input >= STORAGE_SIZE)
			storage = my_realloc(storage, starting_input + 1);
		storage[starting_input++] = curr_char;
	}

	storage[starting_input] = '\0';
	update_buff(the_storage_ptr, size_of_storage, storage, starting_input);
	line_length = starting_input;

	if (starting_input != 0)
		starting_input = 0;

	return (line_length);
}
