/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:14:31 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/28 17:19:12 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_str_len(char **str, char *base, int *pos_neg)
{
	int	index;

	index = 0;
	while (**str == '\t' || **str == '\n' || **str == '\v'
		|| **str == '\f' || **str == '\r' || **str == ' ')
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
		{
			break ;
		}
		index++;
	}
	return (index);
}

int	base_is_valid(char *base, int *len)
{
	int	id_1;
	int	id_2;

	if (*len < 2)
		return (0);
	id_1 = 0;
	id_2 = 1;
	while (base[id_1])
	{
		if (base[id_1] == '-' || base[id_1] == '+' || base[id_1] == ' '
			|| base[id_1] == '\t' || base[id_1] == '\n' || base[id_1] == '\v'
			|| base[id_1] == '\f' || base[id_1] == '\r')
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

int	ft_atoi_convert(int size, char *str, char *base, int *b_len)
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
				nbr = nbr * *b_len + index_2;
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
	int	*b_len;
	int	*pos_neg;
	int	num1;
	int	num2;

	num1 = 0;
	while (base[num1])
		num1++;
	b_len = &num1;
	num2 = 1;
	pos_neg = &num2;
	if (!base_is_valid(base, b_len))
		return (0);
	if (!ft_str_len(&str, base, pos_neg))
		return (0);
	nbr = ft_atoi_convert(ft_str_len(&str, base, pos_neg), str, base, b_len);
	return (*pos_neg * nbr);
}
