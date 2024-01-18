#include "header.h"

/**
 * f_queue - Switch the stack to queue mode
 * @stack: Pointer to the stack
 * @lineNumber: Line number in the file
 *
 * Description: This function switches the stack to queue mode.
 */
void f_queue(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
	bus.isStack = 1;
}

/**
 * queue_node - Add a new node to the tail of the stack
 * @stack: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 *
 * Description: This function adds a new node to the tail of the stack.
 */
void queue_node(stack_t **stack, int value)
{
	stack_t *newNode, *current;

	current = *stack;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->next = NULL;

	if (current)
	{
		while (current->next)
			current = current->next;
	}

	if (!current)
	{
		*stack = newNode;
		newNode->prev = NULL;
	}
	else
	{
		current->next = newNode;
		newNode->prev = current;
	}
}
