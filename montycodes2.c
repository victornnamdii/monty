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
/**
 * divt - divides top two elements
 * @stack: beginning of stack
 * @line_number: line number
 */
void divt(stack_t **stack, unsigned int line_number)
{
	int quotient;
	stack_t *temp = *stack;
	int leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_div1(line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		error_div2(line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (temp->next->n) / (temp->n);
	temp->next->n = quotient;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
/**
 * mul - multiplies the second top element and first
 * @stack: beginning of stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int prod;
	stack_t *tmp = *stack;
	int len = dlistint_len(*stack);

	if (len < 2)
	{
		error_mul(line_number);
		exit(EXIT_FAILURE);
	}
	prod = (tmp->n) * (tmp->next->n);
	tmp->next->n = prod;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}
