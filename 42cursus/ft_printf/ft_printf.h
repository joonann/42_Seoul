#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_format(char format, va_list ap);

int	zero_min(int n);
void	ft_putnbr(long long n);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);

int	ft_print_hex(unsigned int n, char format);
void	hex_string(char *hex, char format);
int	ft_print_hex_do(unsigned int n, char *hex);
void	ft_puthex(unsigned int n, int print_len, char *hex);

int	ft_print_ptr_hex(uintptr_t ptr);
int	ft_print_ptr(void *p);
void	ft_putptr_hex(uintptr_t n, int print_len, char *hex);

#endif
