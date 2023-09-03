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
	char line[50], *end;
	long answer, number, i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
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
		number = strtol(line, &end, 10);
		if (number <= 0)
			fprintf(stderr, "String cant be converted\n");
		else
		{
			for (i = 2; i < number; i++)
			{
				if ((number % i) == 0)
				{
					answer = number / i;
					printf("%ld=%ld*%ld\n", number, answer, i);
					break;
				}
			}
		}
	}
	fclose(fd);
	return (0);
}
