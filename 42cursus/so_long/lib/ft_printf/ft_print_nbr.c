#include "ft_printf.h"

int	zero_min(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (0);
}

static void	ft_putposnbr(unsigned long long n)
{
	char	i;

	if (!n)
		return ;
	i = n % 10 + '0';
	n = n / 10;
	ft_putposnbr(n);
	write(1, &i, 1);
}

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	ft_putposnbr((unsigned long long)n);
}

int	ft_print_nbr(int n)
{
	int	tmp;
	int	print_len;

	tmp = n;
	print_len = 0;
	if (n < 0)
	{
		print_len++;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		print_len++;
	}
	if (n == 0 || n == -2147483648)
		print_len = zero_min(n);
	else
		ft_putnbr((long long)n);
	return (print_len);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	tmp;
	int		print_len;

	tmp = n;
	print_len = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		print_len++;
	}
	if (n == 0)
		print_len = zero_min(n);
	else
		ft_putnbr((long long)n);
	return (print_len);
}
