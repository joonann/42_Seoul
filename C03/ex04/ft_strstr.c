/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:29:04 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 09:28:23 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	index = 0;
	if (!to_find[index])
		return (str);
	while (*str)
	{
		while (to_find[index])
		{
			if (str[index] != to_find[index])
				break ;
			index++;
		}
		if (!to_find[index])
			return (str);
		index = 0;
		str++;
	}
	return (0);
}
