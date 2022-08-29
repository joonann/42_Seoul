/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:26:00 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/30 02:04:39 by junhkim          ###   ########.fr       */
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
	ft_mutex_destroy(args);
	return (1);
}

int	ft_mutex_destroy(t_args *args)
{
	pthread_mutex_destroy(&(args->print));
	pthread_mutex_destroy(&(args->check));
	pthread_mutex_destroy(&(args->routine));
	pthread_mutex_destroy(&(args->pass_time));
	return (0);
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
	ft_mutex_destroy(args);
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
