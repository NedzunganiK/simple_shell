#include "shell.h"

/**
 * add_sep_node_end - Adds a new node with a separator to the sep_list.
 *
 * @head: Pointer to the head of the sep_list.
 * @sep: Separator character (e.g., ';', '|', or '&').
 * Return: Pointer to the head of the updated sep_list.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - Frees the memory allocated for the sep_list.
 *
 * @head: Pointer to the head of the sep_list.
 * Return: void
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - Adds a new node with a line to the line_list.
 *
 * @head: Pointer to the head of the line_list.
 * @line: Line content (string).
 * Return: Pointer to the head of the updated line_list.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	/* Ensure separate memory is allocated for each line content */
	new->line = _strdup(line);
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - Frees the memory allocated for the line_list.
 *
 * @head: Pointer to the head of the line_list.
 * Return: void
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp->line); /* Free the allocated memory for the line content */
			free(temp);
		}
		*head = NULL;
	}
}

