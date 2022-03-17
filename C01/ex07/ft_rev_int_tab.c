/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:10:09 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/21 13:10:37 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	num;
	int	j;

	i = 0;
	j = size / 2;
	while (i < j)
	{
		num = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = num;
		i++;
		size--;
	}
}
