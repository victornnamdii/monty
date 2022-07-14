#include "monty.h"
/**
 * mod - calculates remainder of div
 * @stack: beginning of stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	stack_t *tmp = *stack;
	int len = dlistint_len(*stack);

	if (len < 2)
	{
		error_modu(line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		error_div2(line_number);
		exit(EXIT_FAILURE);
	}
	rem = (tmp->next->n) % (tmp->n);
	tmp->next->n = rem;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}
/**
 * pchar - prints char at top of stack
 * @stack: beginning g of stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		error_pchar2(line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		errchar(line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
