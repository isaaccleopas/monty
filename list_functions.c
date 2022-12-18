#include "monty.h"

/**
 * add_snodeint - add a new node at the beginning
 * @head: doubly linked list
 * @n: data
 *
 * Return: address of new node or NULL
 */

stack_t *add_snodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}


/**
 * add_snodeint_end - add a new node at end of dlist
 * @head: doubly linked list
 * @n: data
 *
 * Return: address of new node or NULL
 */

stack_t *add_snodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *current;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	current = *head;
	if (current == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		while (current->next)
			current = current->next;
		new_node->prev = current;
		current->next = new_node;
	}
	return (new_node);
}


/**
 * free_slistint - frees a slist_int list
 * @head: start of list
 *
 * Return: nothing
 */

void free_slistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * slistint_len - get number of elements in a list
 * @h: head of doubly linked list
 *
 * Return: number of elements
 */

size_t slistint_len(const stack_t *h)
{
	const stack_t *current;
	unsigned int num;

	current = h;
	num = 0;
	while (current)
	{
		num++;
		current = current->next;
	}
	return (num);
}
