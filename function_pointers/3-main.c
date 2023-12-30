#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * main - Doing calc
 * @argv: argument vector.
 * @argc: argument count.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int result;
	int (*opt)(int, int);
	char *op;

	if (argc > 4 || argc < 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = malloc(strlen(argv[2]) + 1);
	strcpy(op, argv[2]);

	if (strcmp(op, "+") && strcmp(op, "-") && strcmp(op, "*")
			&& strcmp(op, "/") && strcmp(op, "%"))
	{
		printf("Error\n");
		exit(99);
	}

	if ((!strcmp(argv[2], "/") || !strcmp(argv[2], "%")) && (atoi(argv[3]) == 0))
	{
		printf("Error\n");
		exit(100);
	}

	opt = get_op_func(argv[2]);
	result = opt(atoi(argv[1]), atoi(argv[3]));

	printf("%d\n", result);

	free(op);
	return (0);
}
