#include <stddef.h>

/**
 * my_strncmp - Compare two strings up to a given number of bytes.
 * @st1: The first string to compare.
 * @st2: The second string to compare.
 * @number: The maximum number of bytes to compare.
 *
 * Return: Negative if st1 is less than st2, positive if st1 is greater
 *         than st2, or 0 if st1 is equal to st2.
 */
int my_strncmp(const char *st1, const char *st2, size_t number)
{
	size_t idx = 0;

	while (idx < number)
	{
		if (st1[idx] != st2[idx])
			return ((st1[idx] < st2[idx]) ? -1 : 1);
		else if (st1[idx] == '\0')
			return (0);
		idx++;
	}
	return (0);
}
