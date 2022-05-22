#include "ft_printf.h"

int	ft_print_ptr_hex(uintptr_t ptr)
{
	
}

int	ft_print_ptr(void *p)
{
	uintptr_t	ptr;
	int		print_len;

	ptr = (uintptr_t)ptr_address;
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
