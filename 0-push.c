#include "monty.h"

/**
 * custom_push - add node to the stack or queue
 * @head: pointer to the stack or queue head
 * @line_number: line number in the file
 *
 * Description: This function adds a node to the stack or queue based on the
 * global variable bus.lifi (stack or queue flag)
 */

void custom_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
			j++;
		for (; bus.argument[j] != '\0'; j++)
		{
			if (bus.argument[j] > 57 || bus.argument[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.argument);
	if (bus.isStack == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
