NAME = push_swap
CC = cc
RM = rm -rf
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = ft
FLAGS = $(CFLAGS) -L$(LIB_DIR) -l$(LIB)

SRCS = main.c

OBJS = $(SRCS:.c=.o)

%.o: $.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) $(OBJS) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY:all re fclean clean
