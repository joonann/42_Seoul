/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:28:05 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/27 11:32:59 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] + 32;
		index++;
	}
	if (str[0] && str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	index = 1;
	while (str[index])
	{
		if (!(str[index - 1] >= 'A' && str[index - 1] <= 'Z')
			&& (!(str[index - 1] >= 'a' && str[index - 1] <= 'z'))
			&& (!(str[index - 1] >= '0' && str[index - 1] <= '9')))
		{
			if (str[index] >= 'a' && str[index] <= 'z')
				str[index] = str[index] - 32;
		}
		index++;
	}
	return (str);
}
