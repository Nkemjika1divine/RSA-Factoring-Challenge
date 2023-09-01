#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);

	return (n);
}



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
