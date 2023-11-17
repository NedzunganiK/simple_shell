#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * @i_eof: A pointer to an integer that will store the return value of getline.
 *        It indicates whether the end-of-file (EOF) has been reached.
 *
 * Return: A pointer to the string containing the user input.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
