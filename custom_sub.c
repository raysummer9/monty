#include "monty.h"
/**
 * custom_sub - subtracts top element from second element
 * @stack: pointer to stack head
 * @line_number: line number in the field
 */
void custom_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Sub unsuccessful; size of stack is too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	custom_pop(stack, line_number);
}
