#include "monty.h"

/**
 * free_stack - Frees a doubly linked list
 * @stack: Pointer to the stack head
 *
 * Description: This function frees the memory allocated for a doubly linked list.
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *nextNode;

	current = stack;
	while (current)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}
