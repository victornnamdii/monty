#include "monty.h"
/**
 * add - adds two elemts
 * @stack: beginning of stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next = NULL;
	int sum, leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_add(line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	sum = (*stack)->n + (((*stack)->next)->n);
	next->n = sum;
	*stack = next;
	free(head);
}
/**
 * nop - performs nothing
 * @stack: beginning of stack
 * @line_number: ine number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
/**
 * sub - subtracts top 2 elements
 * @stack: beginning of stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff, leng;
	stack_t *temp = *stack;

	leng = dlistint_len(*stack);
	if (leng < 2)
	{
		error_sub(line_number);
		exit(EXIT_FAILURE);
	}
	diff = (temp->next->n) - (temp->n);
	temp->next->n = diff;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
