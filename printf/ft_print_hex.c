#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	int	print_len;
	char	hex[17];

	print_len = 0;
	hex_string(hex, format);
	if (format == 'x')
	{
		
		print_len = ft_print_hex_low(n);
	}
	else
		print_len = ft_print_hex_up(n);
	return (print_len);
}

void	hex_string(char *hex, char format)
{
	int	i;
	char	c;

	i = 0;
	if (format == 'x')
		c = 'a';
	else if (format == 'X')
		c = 'A';
	while (i < 10)
	{
		hex[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		str[i] = c;
		i++;
		c++;
	}
	str[i] = 0;
}

int	ft_print_hex_low(unsigned int n)
{
	char		*hex;
	int		print_len;
	unsigned int	tmp;

	tmp = n;
	print_len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		print_len++;
		return (print_len);
	}
	hex = (char *)malloc(17);
	if (!hex)
		return (0);
	
}
