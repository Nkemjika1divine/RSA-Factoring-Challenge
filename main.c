#include "main.h"

/**
 * main - runs the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char line[20];
	int number;

	if (argv == 0)
	{
		fprintf(stderr, "Usage: factor <file>\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fd) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		number = atoi(line);

