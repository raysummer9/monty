#include "monty.h"
/**
 * custom_pop - removes the top element from the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void custom_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: Pop can't be performed in empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
