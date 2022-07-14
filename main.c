#include "main.h"

stack_t *h;
FILE *file;
char *value;
/**
 * get_func - gets required function
 * @opcode: opcode from instruction
 * Return: pointer to function
 */
void (*get_func(char *opcode))(stack_t**, unsigned int)
{
	int index = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	while (ops[index].opcode)
	{
		if (strcmp(opcode, ops[index].opcode) == 0)
			return (ops[index].f);
		index++;
	}
	return (NULL);
}
/**
 * run_monty - Runs the opcode command
 * @buffer: line from file
 * @line_number: the line number
 */
void run_monty(char *buffer, unsigned int line_number)
{
	void (*f)(stack_t**, unsigned int);
	char *cmd = strtok(buffer, " \r\t\n");

	f = get_func(cmd);

	if (f != NULL)
	{
		if (strcmp(cmd, "push") == 0)
			value = strtok(NULL, " \r\t\n");
		f(&h, line_number);
	}
	else
	{
		error_op(line_number, cmd);
		if (buffer)
			free(buffer);
		if (h)
			free_dlistint(h);
		exit(EXIT_FAILURE);
	}
}
/**
 * main - entry point
 * @ac: argument count
 * @av: pointer of to arguments
 * Return: EXIT_SUCCESS on success else EXIT_FAILURE
 */
int main(int ac, char **av)
{
	size_t status;
	char *buffer = NULL;
	unsigned int line_number = 0;

	h = NULL;
	value = NULL;
	file = NULL;
	if (ac != 2)
	{
		error_ac();
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		error_fopen(av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &status, file) != EOF)
	{
		line_number++;
		if (buffer[0] != '\n')
			run_monty(buffer, line_number);
	}
	if (buffer)
		free(buffer);
	if (h)
		free_dlistint(h);
	fclose(file);
	return (EXIT_SUCCESS);
}
