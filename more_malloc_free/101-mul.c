#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * isAllDigits - Check if a string contains only digits.
 * @str: The string to check.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int isAllDigits(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0; /* Not all characters are digits */
        str++;
    }
    return 1; /* All characters are digits */
}

/**
 * multiplyNumbers - Multiply two positive numbers.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: The result of the multiplication.
 */
int multiplyNumbers(int num1, int num2)
{
    return num1 * num2;
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
    /* Check the number of arguments */
    if (argc != 3)
    {
        fprintf(stderr, "Error\n");
        return 98;
    }

    /* Check if num1 and num2 are composed of digits */
    if (!isAllDigits(argv[1]) || !isAllDigits(argv[2]))
    {
        fprintf(stderr, "Error\n");
        return 98;
    }

    /* Convert command-line arguments to integers */
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    /* Check if the numbers are positive */
    if (num1 <= 0 || num2 <= 0)
    {
        fprintf(stderr, "Error\n");
        return 98;
    }

    /* Perform multiplication and print the result */
    int result = multiplyNumbers(num1, num2);
    printf("%d\n", result);

    return 0;
}
