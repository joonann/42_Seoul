#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	int	print_len;
	char	hex[17];

	print_len = 0;
	hex_string(hex, format);
	if (n == 0)
	{
		write(1, "0", 1);
		print_len++;
		return (print_len);
	}
		print_len = ft_print_hex_do(n, hex);
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
		hex[i] = c;
		i++;
		c++;
	}
	hex[i] = 0;
}

int	ft_print_hex_do(unsigned int n, char *hex)
{
	int		print_len;
	unsigned int	tmp;

	print_len = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 16;
		print_len++;
	}
	tmp = n;
	ft_puthex(tmp, print_len, hex);
	return (print_len);
}

void	ft_puthex(unsigned int n, int print_len, char *hex)
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
