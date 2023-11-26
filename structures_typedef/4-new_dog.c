#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - creates a new dog structure
 * @name: string from main, name of pet
 * @age: number from main, age of pet
 * @owner: string from main, owner of pet
 *
 * Return: p, pointer to the new dog structure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *p;

	/* Reserve memory for the dog structure */
	p = malloc(sizeof(dog_t));
	if (p == NULL)
		return (NULL);

	/* Allocate memory for name and owner, and copy the content */
	p->name = malloc(strlen(name) + 1);
	p->owner = malloc(strlen(owner) + 1);

	/* Check for allocation failures */
	if (p->name == NULL || p->owner == NULL)
	{
		free(p->name);
		free(p->owner);
		free(p);
		return (NULL);
	}

	/* Copy the content of name and owner */
	strcpy(p->name, name);
	p->age = age;
	strcpy(p->owner, owner);

	return (p);
}
