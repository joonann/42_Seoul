#include "push_swap.h"

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

long long	convert_int(char *str, int *index)
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