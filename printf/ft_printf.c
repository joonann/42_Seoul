#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_format(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(ap, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		print_len += ft_print_char("%");
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	printf_len;

	printf_len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			printf_len += ft_print_char(*str);
		else
		{
			str++;
			printf_len += ft_print_format(ap, *str);
		}
		str++
	}
	va_end(ap);
	return (printf_len);
}
