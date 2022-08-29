NAME = philo

CC = cc
CFLAGS = -Werror -Wall -Wextra

AR = ar -rcs

RM = rm -rf

SRCS = main.c philo_error.c philo_init.c philo_thread.c philo_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
