#include "shell.h"

/**
 * free_data - Frees the memory allocated for the data_shell structure.
 * @datash: Pointer to the data_shell structure.
 * Return: void
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	/* Free the environment variables */
	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);  /* Free the array of environment variables */
	free(datash->pid);       /* Free the process ID string */
}

/**
 * set_data - Initializes the data_shell structure with the provided values.
 * @datash: Pointer to the data_shell structure to be initialized.
 * @av: Argument vector (command-line arguments).
 * Return: void
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	/* Initialize data_shell members */
	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	/* Count the number of environment variables */
	for (i = 0; environ[i]; i++)
		;

	/* Allocate memory for the array of environment variables */
	datash->_environ = malloc(sizeof(char *) * (i + 1));

	/* Copy environment variables into the newly allocated array */
	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point of the shell program.
 * @ac: Argument count.
 * @av: Argument vector (command-line arguments).
 * Return: The exit status of the shell.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;  /* Avoid unused parameter warning */

	signal(SIGINT, get_sigint);  /* Register the signal handler for Ctrl+C */
	set_data(&datash, av);       /* Initialize the data_shell structure */
	shell_loop(&datash);         /* Enter the shell main loop */
	free_data(&datash);          /* Free allocated memory */

	/* Return the exit status of the shell */
	if (datash.status < 0)
		return (255); /* If status is negative, return 255 */

	return (datash.status);
}

