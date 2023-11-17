#include "shell.h"

/**
 * exec_line - Executes the command specified in datash->args[0].
 *
 * @datash: Pointer to the data_shell structure containing command information.
 * Return: Return status of the executed command.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	/* If no command is provided, return success */
	if (datash->args[0] == NULL)
		return (1);

	/* Check if the command is a built-in function */
	builtin = get_builtin(datash->args[0]);

	/* If it is a built-in function, execute it and return its status */
	if (builtin != NULL)
		return (builtin(datash));

	/* If not a built-in function, execute it as an external command */
	return (cmd_exec(datash));
}
