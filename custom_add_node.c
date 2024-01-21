#include "monty.h"

/**
 * addnode - Add a new node to the head of the stack
 * @stack: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 *
 * Description: This function adds a new node to the head of the stack.
 *              If the stack is not empty, it adjusts the previous pointer
 *              of the existing head node to point to the new node.
 */

void add_node(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
