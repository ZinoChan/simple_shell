#include "shell.h"

/**
 * intToString - int to a str
 * @num: integg
 * Return: str
 */
char *intToString(int num)
{
	int negative_num = 0, digCntr = 0, tmp, i = 0, j = 0;
	char *str;

	if (num < 0)
	{
		negative_num = 1;
		num *= -1;
		digCntr++;
	}
	tmp = num;
	while (tmp > 0)
	{
		digCntr++;
		tmp /= 10;
	}
	str = (char *) malloc(sizeof(char) * (digCntr + 1));
	do {
		str[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);

	if (negative_num)
	{
		str[i++] = '-';
	}

	j = i - 1;
	i = 0;
	while (i < j)
	{
		char tmp = str[i];

		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}

	str[digCntr] = '\0';
	return (str);
}

/**
 * my_isdig- is digit
 * @c: integg
 * Return: bool
 */
int my_isdig(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
