#include "monty.h"
/**
 * free_dlistint - frees a doubly linked lists
 * @head: head of list
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}
/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: head of list
 * @n: data of new node
 * Return: the address of the new element, or
 * NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp = malloc(sizeof(stack_t));

	if (head == NULL || tmp == NULL)
		return (NULL);
	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = NULL;

	if (*head != NULL)
	{
		tmp->next = *head;
		(*head)->prev = tmp;
	}

	*head = tmp;

	return (*head);
}
/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: doubly linked lists
 * Return: the number of nodes
 */
size_t dlistint_len(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}
