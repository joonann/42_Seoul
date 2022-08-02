# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node {
	int	cont;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info {
	int	*arr;
	int	size;
	int	min;
	int	max;
	t_node	*a;
	t_node	*b;
	t_node	*a_top;
	t_node	*a_bot;
	t_node	*b_top;
	t_node	*b_bot;
}	t_info;

void	error_exit(int check)
{
	if (check > 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		exit(1);
}
// Error 출력하면서 exit 만 해줌
void	stack_free(t_node *node)
{
	t_node *tmp;

	while (node->next)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(node);
}
// stack의 모든 노드 free 해줌
void	error_free(t_info *info, int check) // check가 0이면 error출력 없이 종료
{
	if (info->a)
		stack_free(info->a);
	if (info->b)
		stack_free(info->b);
	if (info->arr)
		free(info->arr);
	free(info);
	error_exit(check);
}
// free 후 exit 해줌

void	atoll_plus_minus_check(char *argv_str, int *index, t_info *info)
{
	if (argv_str[*index] == '+' || argv_str[*index] == '-')
	{
		if (!ft_isdigit(argv_str[*index + 1]))
			error_free(info, 1);
		(*index)++;
	}
	else
		error_free(info, 1);
} 

void	arr_size(int argc, char **argv, t_info *info)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		error_free(info, 0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				atoll_plus_minus_check(argv[i], &j, info);
			info->size++;
			while (ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] == ' ')
				j++;
		}
		i++;
	}
}

static long long	convert_int(char *str, int *index)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]) && result <= 10000000000)
	{
		result *= 10;
		result += str[i] - '0';
		(*index)++;
		i++;
	}
	return (result);
}

long long	ft_atoll(char *str, int *index)
{
	long long	result;
	int			sign;

	sign = 1;
	if (str[*index] == '-')
		sign = -1;
	if (str[*index] == '-' || str[*index] == '+')
		(*index)++;
	result = convert_int(&str[*index], index);
	if (str[*index] == ' ')
		(*index)++;
	result *= sign;
	return (result);
}

long long	atoll_to_int(char *str, t_info *info, int *index)
{
	long long tmp;

	tmp = ft_atoll(str, index);
	if (tmp > INT_MAX || tmp < INT_MIN)
		error_free(info, 1);
	return (tmp);
}

// void	stack_parse_loop(int size, char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		{
// 			while (argv[i][j])
// 			{
				
// 			}
// 		}
// 	}
// }

t_info	*info_init(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		error_exit(1);
	info->arr = NULL;
	info->size = 0;
	info->max = 0;
	info->min = 0;
	info->a = NULL;
	info->b = NULL;
	info->a_top = NULL;
	info->b_top = NULL;
	info->a_bot = NULL;
	info->b_bot = NULL;
	return (info);
}

void	arr_init(t_info *info)
{
	info->arr = (int *)ft_calloc(info->size, sizeof(int));
	if (!info->arr)
		error_free(info, 1);
}

void	argv_to_arr(t_info *info, char **argv)
{
	int	i;
	int	j;
	int	arr_index;

	arr_init(info);
	i = 1;
	arr_index = 0;
	while (argv[i])
	{
		if (!ft_strncmp(argv[i], " ", 2))
			error_free(info, 1);
		j = 0;
		while (argv[i][j])
		{
			info->arr[arr_index] = atoll_to_int(argv[i], info, &j);
			arr_index++;
		}
		i++;
	}
}

void	arr_bubble_sort(int *arr, t_info *info)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i] == arr[j])
				error_free(info, 1);
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int	i = 5;

	info = info_init();
	arr_size(argc, argv, info);
	argv_to_arr(info, argv);
	arr_bubble_sort(info->arr, info);
//	arr_to_stack(info);
//	stack_sort(info);
//	print_cmd?

	printf("arr[%d] = %d\n", i, info->arr[i]);

	return (0);
}