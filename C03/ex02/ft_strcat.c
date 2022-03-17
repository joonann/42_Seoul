/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:52 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/22 22:20:24 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	d_index;
	int	s_index;

	d_index = 0;
	s_index = 0;
	while (dest[d_index])
	{
		d_index++;
	}
	while (src[s_index])
	{
		dest[d_index] = src[s_index];
		d_index++;
		s_index++;
	}
	dest[d_index] = 0;
	return (dest);
}
