#include "header.h"

/**
 * addnode - Add a new node to the head of the stack
 * @stack: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 *
 * Description: This function adds a new node to the head of the stack.
 *              If the stack is not empty, it adjusts the previous pointer
 *              of the existing head node to point to the new node.
 */

void addnode(stack_t **stack, int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;

	if (*stack != NULL)
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	else
	{
		newNode->next = NULL;
	}

	*stack = newNode;
}
