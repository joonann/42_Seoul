NAME = pipex

CC = cc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs
RM = rm -rf

SRCS = error.c path.c pipex.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(MAKE) -C ./libft 
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY:all re fclean clean bonus
