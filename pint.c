#include "monty.h"

/**
 * pint - prints value at top of the stack
 * @stack : the stack
 * @line_number: current line in file
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current)
	{
		printf("%d\n", current->n);
	}
	else
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
	}

}
