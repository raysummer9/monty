#include "monty.h"

/**
 * execute - Execute Monty opcodes
 * @content: Line content from the Monty file
 * @stack: Pointer to the stack or queue head
 * @line_number: Line number in the file
 * @file: Pointer to the Monty file
 *
 * Return: 0 if successful, otherwise exits with EXIT_FAILURE
 */

int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	unsigned int i = 0;
	char *opcode;

	instruction_t opcodes[] = {
		{"push", custom_push}, {"pall", custom_pall},
		{NULL, NULL}
	};

	opcode = strtok(content, "\n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.argument = strtok(NULL, "\n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
