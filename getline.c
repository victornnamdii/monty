#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>


#if !(defined _POSIX_C_SOURCE)
#endif

#if !(defined _POSIX_C_SOURCE) || _POSIX_C_SOURCE < 200809L

#if !(defined SSIZE_MAX)
#define SSIZE_MAX (SIZE_MAX >> 1)
#endif
/**
 * getline - placeholder
 * @pline_buf: placeholder
 * @pn: placeholder
 * @fin: placeholder
 * Return: placeholder
 */
ssize_t getline(char **pline_buf, size_t *pn, FILE *fin)
{
	const size_t INITALLOC = 16, ALLOCSTEP = 16;
	size_t num_read = 0, n_realloc;
	int c;
	char *tmp;

	if ((pline_buf == NULL) || (pn == NULL) || (fin == NULL))
		return (-1);
	if (*pline_buf == NULL)
	{
		*pline_buf = malloc(INITALLOC);
		if (*pline_buf == NULL)
			return (-1);
		*pn = INITALLOC;
	}
	while ((c = getc(fin)) != EOF)
	{
		num_read++;
		if (num_read >= *pn)
		{
			n_realloc = *pn + ALLOCSTEP;
			tmp = realloc(*pline_buf, n_realloc + 1);
			if (tmp != NULL)
			{
				*pline_buf = tmp;
				*pn = n_realloc;
			}
			else
				return (-1);
			if (*pn > SSIZE_MAX)
				return (-1);
		}
		(*pline_buf)[num_read - 1] = (char) c;
		if (c == '\n')
			break;
	}
	if (c == EOF)
		return (-1);
	(*pline_buf)[num_read] = '\0';
	return ((ssize_t) num_read);
}

#endif
