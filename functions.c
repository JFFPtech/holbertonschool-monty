#include "monty.h"

/**
 * f_pop - remove top node from stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 */

void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		free_stack(*head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

/**
 * f_pint - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 */

void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		free_stack(*head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * f_nop - do nothing
 * @head: pointer to pointer of first node
 * @counter: line counter
 */

void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
