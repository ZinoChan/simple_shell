#include "shell.h"

/**
 * my_atoi - implementation of built in atoi
 * @string: the string
 * Return: integer
*/

int my_atoi(const char *string)
{
	int ans = 0, sign_val = 1;

	while (*string == ' ' || *string == '\t' || *string == '\n')
		string++;

	if (*string == '-')
	{
		sign_val = -1;
		string++;
	}
	else if (*string == '+')
		string++;

	while (*string >= '0' && *string <= '9')
	{
		ans = ans * 10 + (*string - '0');
		string++;
	}

	return (sign_val * ans);
}
