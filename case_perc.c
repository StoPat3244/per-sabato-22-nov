#include "ft_printf.h"

/*
perc: The character %
count: Reference to the printed character counter.
Print the character and increase the counter.
*/
void	case_perc(char perc, ssize_t *count)
{
	write(out, &perc, 1);
	*count = *count + 1;
}
