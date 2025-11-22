static size_t	check_case(const char c, va_list args)
{
	//metti ft_putchar o string per stampare o forse anche ft_putchar_fd
	if (c == 'c')
		count = case_char(va_arg(ap, int));
	else if (c == 's')
		count = case_string(va_arg(ap, char *));
	else if (c == 'p')
		count = case_void(va_arg(ap, void *));
	else if (c == 'd')
		count = case_decimal(va_arg(ap, int));
	else if (c == 'i')
		count = case_integer(va_arg(ap, int));
	else if (c == 'u')
		count = case_u_decimal(va_arg(ap, unsigned int));
	else if (c == 'x')
		count = case_hex_lowcase(va_arg(ap, unsigned int));
	else if (c == 'X')
		count = case_hex_upcase(va_arg(ap, unsigned int));
	else if (c == '%')
		count = case_perc(c);
	else				//Default for unmanaged flags
	{
		write(out, "%", 1);
		write(out, &c, 1);
		count += 2;
	}
	return (count);
}


int	ft_printf(const char *str, ...)
{
	va_list args;
	size_t count;
	size_t i;

	if (!str)
		return (NULL);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += check_case(str[i], args);
		}
		else
			count += ft_putchar_fd(str[i]);
		i++;
	}
	va_end(args)
	return (count);
}
