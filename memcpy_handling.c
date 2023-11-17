#include "shell.h"

/**
 * _memcpy - Copies 'size' bytes from 'ptr' to 'newptr'.
 * @newptr: Destination memory buffer.
 * @ptr: Source memory buffer.
 * @size: Number of bytes to copy.
 * Return: void
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - Reallocates a memory block with a new size.
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: Old size of the memory block.
 * @new_size: New size to reallocate the memory block.
 * Return: Pointer to the newly reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - Reallocates a dynamic array of strings.
 * @ptr: Pointer to the array of strings.
 * @old_size: Old size of the array.
 * @new_size: New size to reallocate the array.
 * Return: Pointer to the newly reallocated array of strings.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}

