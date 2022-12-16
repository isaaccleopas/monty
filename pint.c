#include <stdio.h>
#include <stdlib.h>

/**
 * pint - prints value at top of the stack
 * @stack : the stack
 *
 * Return: void
 */

void pint(stack_t *stack)
{
	stact_t *current;
	int line;

	if (stack)
	{
		line = 0;
		current = stack;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
			line++;
		}
	}
	else
	{
		fprintf(2,"L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

}
