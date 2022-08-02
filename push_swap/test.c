typedef struct s_stack {
	struct s_stack	*prev;
	int	cont;
	struct s_stack	*next;
}	t_stack;
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->prev = 0;
	a->cont = 10;
	a->next = b;
	b->prev = a;
	b->cont = 20;
	b->next = 0;

	printf("a : %d\n b : %d\n", a->cont, b->cont);
	free(a);
	free(b);
	return (0);
}