NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
SRCS = ft_printf.c ft_print_hex.c ft_print_nbr.c ft_print_ptr.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: clean all

.PHONY: all clean fclean re
