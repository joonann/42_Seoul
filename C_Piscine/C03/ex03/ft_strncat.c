/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:42:31 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/22 22:21:07 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d_index;
	unsigned int	s_index;

	d_index = 0;
	s_index = 0;
	while (dest[d_index])
	{
		d_index++;
	}
	while (src[s_index] && s_index < nb)
	{
		dest[d_index] = src[s_index];
		d_index++;
		s_index++;
	}
	dest[d_index] = 0;
	return (dest);
}
