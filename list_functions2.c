#include "monty.h"


/**
 * delete_snodeint_at_index - deltes a node in a doubly linked list
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_snodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < index)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * get_snodeint_at_index - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
stack_t *get_snodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}


/**
 * insert_snodeint_at_index - inserts a node at a given index
 * @h: double pointer to the list
 * @index: index of the node to insert
 * @n: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
stack_t *insert_snodeint_at_index(stack_t **h, unsigned int index, int n)
{
	unsigned int i;
	stack_t *new;
	stack_t *temp = *h;

	if (index == 0)
		return (add_snodeint(h, n));

	for (i = 0; temp && i < index; i++)
	{
		if (i == index - 1)
		{
			if (temp->next == NULL)
				return (add_snodeint_end(h, n));
			new = malloc(sizeof(stack_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
