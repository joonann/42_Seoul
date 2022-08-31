NAME = push_swap

CC = cc
RM = rm -rf
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./libft
LIBFT = libft.a

SRCS = arg_to_arr.c arg_to_arr_2.c cmd_pa_pb.c cmd_ra_rb.c \
		cmd_rra_rrb.c cmd_sa_sb.c divide.c error.c \
		push_swap.c sort_five.c sort_five_2.c sort_four.c \
		sort_three_a.c sort_three_b.c sort_two.c sort_under.c \
		sort.c stack.c

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
