#include "ft_printf.h"

/*
c: The character to print.
count: Reference to the printed character counter.
Print the character and increase the counter.
*/
void	case_char(int c, ssize_t *count)
{
	unsigned char	uc;

	uc = (unsigned char) c;		//I don't think it's strictly necessary
	write(out, &uc, 1);
	*count = *count + 1;
}
