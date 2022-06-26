# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 22:00:06 by junhkim           #+#    #+#              #
#    Updated: 2022/06/26 09:04:44 by junhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_junhkim.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line

LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c

GNL = get_next_line.c get_next_line_utils.c

FT_PRINTF = ft_print_hex.c ft_print_nbr.c ft_print_ptr.c ft_printf.c

all: $(NAME)

$(NAME): libft ft_printf gnl

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
ft_printf: $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

clean:
	rm -rf $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
	rm -rf $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF:.c=.o))
	rm -rf $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft ft_printf gnl
