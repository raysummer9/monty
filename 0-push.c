#include "monty.h"

/**
 * custom_push - add node to the stack or queue
 * @stack: pointer to the stack or queue head
 * @lineNumber: line number in the file
 *
 * Description: This function adds a node to the stack or queue based on the
 * global variable bus.lifi (stack or queue flag)
 */

void custom_push(stack_t **stack, unsigned int lineNumber)
{
	int value, j = 0, flag = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
			j++;
		for (; bus.argument[j] != '\0'; j++)
		{
			if (bus.argument[j] > '9' || bus.argument[j] < '0')
				flag = 1;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
			fclose(bus.filePointer);
			free(bus.lineContent);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		fprintf(stderr, "L%d: usahe: push integer\n", lineNumber);
		fclose(bus.filePointer);
		free(bus.lineContent);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.argument);
	if (bus.isStack == 0)
		addnode(stack, value);
	else
		queue_node(stack, value);
}
