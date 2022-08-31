/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:00:09 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/29 17:56:48 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str);

int	ft_is_base(char *str, char *base, int str_index)
{
	int	index_2;
	int	flag;

	flag = 0;
	index_2 = 0;
	while (base[index_2])
	{
		if (str[str_index] == base[index_2])
		{
			flag = 1;
			break ;
		}
		index_2++;
	}
	return (flag);
}

int	ft_str_cut(char **str, char *base, int *pos_neg)
{
	int	index;

	index = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*pos_neg = *pos_neg * (-1);
		(*str)++;
	}
	if (!ft_is_base(*str, base, index))
		return (0);
	while ((*str)[index])
	{
		if (!ft_is_base(*str, base, index))
			break ;
		index++;
	}
	return (index);
}

int	base_valid(char *base)
{
	int	id_1;
	int	id_2;
	int	len;

	len = str_len(base);
	if (len < 2)
		return (0);
	id_1 = 0;
	id_2 = 1;
	while (base[id_1])
	{
		if (base[id_1] == '-' || base[id_1] == '+' || base[id_1] == ' '
			|| (base[id_1] >= 9 && base[id_1] <= 13))
			return (0);
		while (base[id_2])
		{
			if (base[id_1] == base[id_2])
				return (0);
			id_2++;
		}
		id_1++;
		id_2 = id_1 + 1;
	}
	return (1);
}

int	ft_atoi_convert(int size, char*str, char *base, int b_len)
{
	int	index_1;
	int	index_2;
	int	nbr;

	index_1 = 0;
	nbr = 0;
	while (index_1 < size)
	{
		index_2 = 0;
		while (base[index_2])
		{
			if (str[index_1] == base[index_2])
			{
				nbr = (nbr * b_len) + index_2;
				break ;
			}
			index_2++;
		}
		index_1++;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	*pos_neg;
	int	num;
	int	size_of_cut;
	int	b_len;

	num = 1;
	pos_neg = &num;
	if (!ft_str_cut(&str, base, pos_neg))
		return (0);
	size_of_cut = ft_str_cut(&str, base, pos_neg);
	b_len = str_len(base);
	nbr = ft_atoi_convert(size_of_cut, str, base, b_len);
	return (*pos_neg * nbr);
}
