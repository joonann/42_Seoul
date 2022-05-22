#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int	ft_print_format(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len = ft_print_char(va_arg(ap, int));
	else if (format == 's')
		print_len = ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len = ft_print_ptr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		print_len = ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		print_len = ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
	{
		write(1, "%", 1);
		print_len++;
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	printf_len;
	int	i;

	printf_len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			printf_len += ft_print_char(str[i]);
		else
		{
			i++;
			printf_len += ft_print_format(ap, str[i]);
		}
		i++;
	}
	va_end(ap);
	return (printf_len);
}
