# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 22:53:27 by junhkim           #+#    #+#              #
#    Updated: 2022/06/26 09:04:33 by junhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

SRCS_DIR = ./src/
LIB_DIR = ./lib/

LIB_NAME = ./lib/lib/junhkim.a
INCS = -I include

SRCS = key.c key_find_p.c image.c main.c map_read.c error.c

LIBS = $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ -L $(LIB_DIR) -l_junhkim -L./mlx -lmlx \
		-framework OpenGL -framework Appkit

all: $(NAME)

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
