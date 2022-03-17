/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:59:57 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/29 21:25:56 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	base_valid(char *base);

int	str_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*itoa_base_pos(int nbr_int, char *base_to)
{
	int		size;
	int		nbr_temp;
	char	*dest;

	size = 0;
	nbr_temp = nbr_int;
	while (nbr_int > 0)
	{
		size++;
		nbr_int = nbr_int / str_len(base_to);
	}
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	dest[size--] = 0;
	while (size >= 0)
	{
		dest[size] = base_to[nbr_temp % str_len(base_to)];
		nbr_temp = nbr_temp / str_len(base_to);
		size--;
	}
	return (dest);
}

char	*itoa_base_neg(int nbr_int, char *base_to)
{
	int			size;
	long long	nbr_temp;
	char		*dest;

	size = 0;
	nbr_temp = nbr_int * (-1);
	while (nbr_temp > 0)
	{
		size++;
		nbr_temp = nbr_temp / str_len(base_to);
	}
	dest = (char *)malloc(sizeof(char) * size + 2);
	if (!dest)
		return (0);
	dest[size + 1] = 0;
	dest[0] = '-';
	nbr_temp = nbr_int * (-1);
	while (size > 0)
	{
		dest[size] = base_to[nbr_temp % str_len(base_to)];
		nbr_temp = nbr_temp / str_len(base_to);
		size--;
	}
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest_str;
	int		nbr_int;

	if (!(base_valid(base_from)) || !(base_valid(base_to)))
		return (NULL);
	nbr_int = ft_atoi_base(nbr, base_from);
	if (nbr_int == 0)
	{
		dest_str = (char *)malloc(sizeof(char) * 2);
		if (!dest_str)
			return (0);
		dest_str[0] = base_to[0];
		dest_str[1] = 0;
	}	
	else if (nbr_int > 0)
		dest_str = itoa_base_pos(nbr_int, base_to);
	else
		dest_str = itoa_base_neg(nbr_int, base_to);
	return (dest_str);
}
