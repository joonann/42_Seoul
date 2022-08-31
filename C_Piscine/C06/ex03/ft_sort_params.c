/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:44:24 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 21:54:08 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *str1, char *str2)
{
	int	index;

	index = 0;
	while (str1[index] || str2[index])
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
	}
	return (0);
}

char	**ft_sort_parms(int argc, char **argv)
{
	int		loop;
	int		index;
	char	*temp;

	loop = 1;
	index = 1;
	while (loop < argc)
	{
		while (argv[index + 1])
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
			{
				temp = argv[index];
				argv[index] = argv[index + 1];
				argv[index + 1] = temp;
			}
			index++;
		}
		loop++;
		index = 0;
	}
	return (argv);
}

void	print_arr(char *arr)
{
	int		loop;
	char	ch;

	loop = 0;
	while (arr[loop])
	{
		ch = arr[loop];
		write(1, &ch, 1);
		loop++;
	}
}

int	main(int argc, char **argv)
{
	int		index;

	argv = ft_sort_parms(argc, argv);
	index = 1;
	while (index < argc)
	{
		print_arr(argv[index]);
		write(1, "\n", 1);
		index++;
	}
	return (0);
}
