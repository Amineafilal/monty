#include "monty.h"

/**
 * not_int - Checks if a string represents a non-negative integer
 * @s: String to check
 * Return: 1 if not an integer, 0 if it is an integer
 */
int not_int(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-' && i == 0)
			i++;
		if (s[i] >= 58 || s[i] <= 47)
			return (1);
		i++;
	}
	return (0);
}
