#include <stdio.h>
#include <string.h>
#include "3-calc.h"
/**
 * get_op_func - Getting operation function.
 * @s: operator.
 *
 * Return: Result.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};
	unsigned long int i = 0;

	while (i < sizeof(ops) / sizeof(ops[0]))
	{
		if (!strcmp(s, ops[i].op))
		{
			return (ops[i].f);
		}
		i++;
	}

	return (NULL);
}
