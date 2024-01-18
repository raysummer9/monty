#include "monty.h"

/**
 * custom_pall - Prints the stack or queue
 * @stack: Pointer to the stack or queue head
 * @lineNumber: Line number in the file (not used)
 *
 * Description: This function prints the elements in the stack or queue.
 */
void custom_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
