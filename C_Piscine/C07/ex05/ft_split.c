/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:00:28 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/30 19:42:24 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str, char end_ch)
{
	int	count;

	count = 0;
	while (str[count] != end_ch)
		count++;
	return (count);
}

char	*ft_split_ch_unify(char *str, char *charset, char split_ch)
{
	int		index1;
	int		index2;
	char	*temp_str;

	temp_str = (char *)malloc(sizeof(char) * (str_len(str, 0) + 2));
	if (!temp_str)
		return (0);
	index1 = 0;
	index2 = 0;
	while (str[index1])
	{
		temp_str[index1] = str[index1];
		while (charset[index2])
		{
			if (str[index1] == charset[index2])
				temp_str[index1] = split_ch;
			index2++;
		}
		index1++;
		index2 = 0;
	}
	temp_str[index1] = split_ch;
	temp_str[index1 + 1] = 0;
	return (temp_str);
}

char	**mem_set(char *str, char split_ch, int *size)
{
	char	**dest_arr;

	while (*str != 0)
	{
		while (*str && *str != split_ch)
		{
			if (*str != split_ch)
			{
				(*size)++;
				str++;
			}
			while (*str && (*str != split_ch))
				str++;
		}
		while (*str == split_ch)
			str++;
	}
	dest_arr = (char **)malloc(sizeof(char *) * (*size + 1));
	if (!dest_arr)
		return (0);
	return (dest_arr);
}

char	**ft_split_str(char **dest_str, char *str, char split_ch, int *size)
{
	int	index1;
	int	index2;
	int	each_str_len;

	index1 = 0;
	index2 = 0;
	while (index1 < *size)
	{
		while (*str == split_ch)
			str++;
		each_str_len = str_len(str, split_ch);
		dest_str[index1] = (char *)malloc(sizeof(char) * (each_str_len + 1));
		if (!dest_str[index1])
			return (0);
		while (*str != '\0' && (*str != split_ch))
		{
			dest_str[index1][index2] = *str;
			index2++;
			str++;
		}
		dest_str[index1][index2] = 0;
		index1++;
		index2 = 0;
	}
	return (dest_str);
}

char	**ft_split(char *str, char *charset)
{
	char	split_ch;
	char	*temp_str;
	char	**dest_arr;
	int		size;

	size = 0;
	split_ch = charset[0];
	if (charset[0] == 0)
	{
		dest_arr = (char **)malloc(sizeof(char *) * 1);
		if (!dest_arr)
			return (0);
		dest_arr[0] = str;
		return (dest_arr);
	}
	temp_str = ft_split_ch_unify(str, charset, split_ch);
	dest_arr = mem_set(temp_str, split_ch, &size);
	dest_arr = ft_split_str(dest_arr, temp_str, split_ch, &size);
	return (dest_arr);
}
