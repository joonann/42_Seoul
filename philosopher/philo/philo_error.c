/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:26:00 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/29 18:27:54 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

int	mutex_destroy_while_init(t_args *args, int index)
{
	int	i;

	i = 0;
	while (i + 1 < index)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->print));
	return (1);
}

int	error_destroy(char *msg, t_args *args, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->print));
	return (error_free(msg, args, philo));
}

int	error_free(char *msg, t_args *args, t_philo **philo)
{
	if (args->forks)
		free(args->forks);
	if (*philo)
		free(*philo);
	return (print_error(msg));
}
