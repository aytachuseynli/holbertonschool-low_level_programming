#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using Binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i = 0, j = size - 1, m;

	if (array == NULL)
		return (-1);

	while (i <= j)
	{
		printf("Searching in array: ");
		for (m = i; m < j; m++)
			printf("%d, ", array[m]);
		printf("%d\n", array[m]);

		m = (i + j) / 2;
		if (array[m] < value)
			i = m + 1;
		else if (array[m] > value)
			j = m - 1;
		else
			return (m);
	}

	return (-1);
}
