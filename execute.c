#include "monty.h"

/**
 * execute - Execute Monty commands
 * @line: Monty command line
 * @stack: Pointer to the stack
 * @counter: Line number in the Monty file
 * @file: Pointer to the Monty file
 */
void execute(char *line, stack_t **stack, unsigned int counter, FILE *file)
{
    char *opcode;
    int value;

    /*Tokenize the command line to get the opcode and value*/
    opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        char *arg = strtok(NULL, " \t\n");
        if (arg == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(file);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }

        value = atoi(arg);
        push(stack, value);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(*stack);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        fclose(file);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
}

