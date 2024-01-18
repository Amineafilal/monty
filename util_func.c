#include "monty.h"

/***/

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
