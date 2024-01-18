#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct Bus - Variables structure carrying values through the program
 * @argument: Value associated with an instruction
 * @filePointer: Pointer to the current file
 * @lineContent: Content of the current line in the file
 * @isStack: Flag indicating whether to use stack (1) or queue (0)
 *
 * Description: Structure carrying values through the program execution
 */

typedef struct bus_s
{
	char *argument;
	FILE *file;
	char *content;
	int isStack;
} bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void custom_push(stack_t **stack, unsigned int line_number);
void custom_pall(stack_t **stack, unsigned int line_number);
void custom_pint(stack_t **stack, unsigned int lineNumber);
void custom_pop(stack_t **stack, unsigned int lineNumber);
void custom_swap(stack_t **stack, unsigned int lineNumber);
void free_stack(stack_t *stack);
int main(int argc, char *argv[]);
void addnode(stack_t **stack, int value);
void queue_node(stack_t **stack, int value);
void f_queue(stack_t **stack, unsigned int lineNumber);
void custom_nop(stack_t **stack, unsigned int lineNumber);
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file);

#endif

