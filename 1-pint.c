#include "monty.h"

/**
 * custom_pint - Print the top element of the stack
 * @stack: Pointer to the stack head
 * @line_number: Line number in the file
 *
 * Description: This function prints the top element of the stack.
 */
void custom_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
