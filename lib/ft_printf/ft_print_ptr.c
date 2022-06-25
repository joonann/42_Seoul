#include "ft_printf.h"

int	ft_print_ptr_hex(uintptr_t n)
{
	char		hex[17];
	int		print_len;
	uintptr_t	tmp;

	tmp = n;
	print_len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex_string(hex, 'x');
	while (tmp > 0)
	{
		tmp /= 16;
		print_len++;
	}
	tmp = n;
	ft_putptr_hex(tmp, print_len, hex);
	return (print_len);
}

int	ft_print_ptr(void *p)
{
	uintptr_t	ptr;
	int		print_len;

	ptr = (uintptr_t)p;
	print_len = 0;
	write(1, "0x", 2);
	print_len += 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		print_len++;
	}
	else
		print_len += ft_print_ptr_hex(ptr);
	return (print_len);
}

void	ft_putptr_hex(uintptr_t n, int print_len, char *hex)
{
	int	i;
	char	*str;

	str = (char *)malloc(print_len + 1);
	if (!str)
		return ;
	i = print_len;
	str[i] = 0;
	i--;
	while (n > 0)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	write(1, str, print_len);
	free(str);
	return ;
}
