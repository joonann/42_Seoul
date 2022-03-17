/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:10:48 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/21 13:11:09 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				num = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = num;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
