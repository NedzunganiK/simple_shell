#include "shell.h"

/**
 * get_sigint - Signal handler for SIGINT (Ctrl+C).
 * @sig: The signal number (unused in this handler)
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
