#include "monty.h"

/**
 * f_queue - Switch the stack to queue mode
 * @head: Pointer to the stack
 * @line_number: Line number in the file
 *
 * Description: This function switches the stack to queue mode.
 */
void custom_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bus.isStack = 1;
}

/**
 * add_queue - Add a new node to the tail of the stack
 * @head: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 *
 * Description: This function adds a new node to the tail of the stack.
 */
void add_queue(stack_t **head, int value)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	if (current)
	{
		while (current->next)
			current = current->next;
	}

	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}
