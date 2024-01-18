#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t readLine = 1;
    stack_t *stack = NULL;
    unsigned int lineCounter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (readLine > 0)
    {
        content = NULL;
        readLine = getline(&content, &size, file);
        bus.content = content;
        lineCounter++;

        if (readLine > 0)
        {
            execute(content, &stack, lineCounter, file);
        }

        free(content);
    }

    free_stack(stack);
    fclose(file);
    return 0;
}

