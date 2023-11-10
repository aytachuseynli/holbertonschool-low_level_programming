#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * number - function to calculate number of words
 * @str: string being passed to check for words
 *
 * Return: number of words
 */
int number(char *str)
{
    int a, num = 0;

    for (a = 0; str[a] != '\0'; a++)
    {
        if (*str == ' ')
            str++;
        else
        {
            for (; str[a] != ' ' && str[a] != '\0'; a++)
                str++;
            num++;
        }
    }
    return (num);
}

/**
 * free_everything - frees the memory
 * @string: pointer values being passed for freeing
 * @i: counter
 */
void free_everything(char **string, int i)
{
    for (; i > 0;)
        free(string[--i]);
    free(string);
}

/**
 * split_word - Helper function to split a word from the string
 * @str: Pointer to the current position in the string
 * @length: Pointer to store the length of the word
 *
 * Return: The word (substring)
 */
char *split_word(char *str, int *length)
{
    char *word_start = str;
    *length = 0;

    while (*str != ' ' && *str != '\0')
    {
        (*length)++;
        str++;
    }

    return word_start;
}

/**
 * process_word - Helper function to process a word and allocate memory
 * @word_start: Pointer to the start of the word
 * @length: Length of the word
 *
 * Return: Allocated memory for the word
 */
char *process_word(char *word_start, int length)
{
    char *word = malloc((length + 1) * sizeof(char));

    if (word == NULL)
        return NULL;

    for (int i = 0; i < length; i++)
        word[i] = word_start[i];

    word[length] = '\0';

    return word;
}

/**
 * strtow - function that splits string into words
 * @str: string being passed
 * Return: null if string is empty or null or function fails
 */
char **strtow(char *str)
{
    int total_words, b = 0, c = 0, length = 0;
    char **words, *found_word;

    if (str == NULL || *str == '\0')
        return NULL;

    total_words = number(str);

    if (total_words == 0)
        return NULL;

    words = malloc((total_words + 1) * sizeof(char *));

    if (words == NULL)
        return NULL;

    while (*str != '\0' && b < total_words)
    {
        if (*str == ' ')
            str++;
        else
        {
            found_word = split_word(str, &length);

            words[b] = process_word(found_word, length);

            if (words[b] == NULL)
            {
                free_everything(words, b);
                return NULL;
            }

            b++;
            c = 0;
            str += length;
        }
    }

    return words;
}

