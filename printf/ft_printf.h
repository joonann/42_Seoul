#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_format(va_list ap, const char format);

int	zero_min(int n);
void	ft_putnbr(long long n);
int	ft_print_nbr(int n);
int	ft_print_unsigned(int n);

#endif
