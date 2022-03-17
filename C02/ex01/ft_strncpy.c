/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:57:50 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/22 11:07:18 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	src_len(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (i >= src_len(src))
			dest[i] = 0;
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
