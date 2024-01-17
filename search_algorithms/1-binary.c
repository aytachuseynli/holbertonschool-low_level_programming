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
    size_t left, right, mid;

    if (array == NULL || size == 0)
        return (-1);

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        printf("Searching in array: ");
        for (left = 0; left <= right; left++)
        {
            printf("%d", array[left]);
            if (left < right)
                printf(", ");
            else
                printf("\n");
        }

        if (array[mid] < value)
            left = mid + 1;
        else if (array[mid] > value)
            right = mid - 1;
        else
            return (mid);
    }

    return (-1);
}
