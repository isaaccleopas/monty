#include "monty.h"

data_t data = {NULL, NULL, NULL, NULL, 0};

/**
 * monty - helper function for main function
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void monty(args_t *args)
{
	size_t len = 0;
	int res = 0;
	void (*code_func)(stack_t **, unsigned int);

	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_number++;
		res = getline(&(data.line), &len, data.fptr);
		if (res < 0)
			break;
		data.words = strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", args->line_number, data.words[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_number);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - entry point for monty bytecode interpreter
 * @ac: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char *argv[])
{
	args_t args;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	args.av = argv[1];
	args.line_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
