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

/**
 * stack - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * queue - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}

/**
 * mod - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_snodeint_at_index(*stack, 0);
	stack_t *node_1 = get_snodeint_at_index(*stack, 1);

	if (slistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_snodeint_at_index(stack, 0);
	delete_snodeint_at_index(stack, 0);
	node = add_snodeint(stack, mod);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
