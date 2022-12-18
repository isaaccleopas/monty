#include "monty.h"

/**
 * swap - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (slistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_snodeint_at_index(*stack, 0);
	num = temp->n;
	delete_snodeint_at_index(stack, 0);
	node = insert_snodeint_at_index(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
