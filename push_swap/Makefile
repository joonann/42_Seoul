NAME = push_swap

CC = cc
RM = rm -rf
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./libft
LIBFT = libft.a

SRCS = push_swap.c arg_to_arr_2.c arg_to_arr.c cmd_pa_pb.c \
		cmd_ra_rb.c cmd_rra_rrb.c cmd_sa_sb.c error.c stack.c \
		sort.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -I$(LIB_DIR) -c $^

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lft

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY:all re fclean clean
