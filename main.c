#include "monty.h"

/***/
char *buf;
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 0;
	int ligne = 1;
	stack_t	*stack = NULL;

	buf = NULL;
	if (argc != 2)
	{
		write(2, "USAGE: monty file", 17);
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		/*cant open*/
	}

	while (getline(&buf, &size, fd)!= -1)
	{
		tokenize(buf, ligne, &stack);
		ligne++;
	}
	free(buf);
	free_dlistint(stack);
	fclose(fd);
	return (0);
	
}
