# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 19:23:12 by junhkim           #+#    #+#              #
#    Updated: 2021/09/30 19:57:33 by junhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs/
INC_DIR = includes/

SRCS = $(SRCS_DIR)ft.putchar.c \
	   $(SRCS_DIR)ft_swap.c \
	   $(SRCS_DIR)ft_putstr.c \
	   $(SRCS_DIR)ft_strlen.c \
	   $(SRCS_DIR)ft_strcmp.c

OBJS = $(SRCS : .c = .o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

$(NAME) : $(OBJS)
	ar -cr $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC_DIR)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re .c .o
