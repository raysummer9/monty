#include "header.h"

/**
 * execute - Execute Monty opcodes
 * @lineContent: Line content from the Monty file
 * @stack: Pointer to the stack or queue head
 * @lineNumber: Line number in the file
 * @filePointer: Pointer to the Monty file
 *
 * Return: 0 if successful, otherwise exits with EXIT_FAILURE
 */

int execute(char *lineContent, stack_t **stack, unsigned int lineNumber, FILE *filePointer)
{
	unsigned int i = 0;
	char *opcode;

	instruction_t opcodes[] = {
		{"push", custom_push}, {"pall", custom_pall},
		{NULL, NULL}
	};

	opcode = strtok(lineContent, "\n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.argument = strtok(NULL, "\n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i]. opcode) == 0)
		{
			opcodes[i].f(stack, lineNumber);
			return (0);
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
		fclose(filePointer);
		free(lineContent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
