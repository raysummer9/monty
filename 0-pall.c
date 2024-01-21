#include "monty.h"

/**
 * custom_pall - Prints the stack or queue
 * @head: Pointer to the stack or queue head
 * @line_number: Line number in the file
 *
 * Description: This function prints the elements in the stack or queue.
 */
void custom_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
