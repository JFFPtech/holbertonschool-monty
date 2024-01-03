#include "monty.h"

/**
 * addnode - add node to top of stack
 * @head: first node
 * @n: new value
 * Return: none
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (aux)
        aux->prev = new_node;

    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}
