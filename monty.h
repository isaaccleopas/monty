#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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


/**
 * struct args_s - structure of arguments from main
 * @av: name of the file from the command line
 * @line_number: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_s
{
	char *av;
	unsigned int line_number;
} args_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @words: parsed line
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

/* op code functions */
void add(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

void (*get_func(char **parsed))(stack_t **, unsigned int);
extern data_t data;
void monty(args_t *args);
int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);
void free_all(int all);

/* linked list */
stack_t *add_snodeint(stack_t **head, const int n);
stack_t *add_snodeint_end(stack_t **head, const int n);
void free_slistint(stack_t *head);


#endif /* _MONTY_H_ */
