#include "monty.h"

char *buf;

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 0;
	int ligne = 1;
	stack_t	*stack = NULL;

	buf = NULL;
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buf, &size, fd) != -1)
	{
		tokenize(buf, ligne, &stack);
		ligne++;
	}
	free(buf);
	free_dlistint(stack);
	fclose(fd);
	return (0);
	
}
