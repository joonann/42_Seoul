/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:26:22 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/30 02:06:42 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init(t_args *args)
{
	if (pthread_mutex_init(&(args->print), NULL))
		return (-1);
	if (pthread_mutex_init(&(args->check), NULL))
	{
		pthread_mutex_destroy(&(args->print));
		return (-1);
	}
	if (pthread_mutex_init(&(args->routine), NULL))
	{
		pthread_mutex_destroy(&(args->print));
		pthread_mutex_destroy(&(args->check));
		return (-1);
	}
	if (pthread_mutex_init(&(args->pass_time), NULL))
	{
		pthread_mutex_destroy(&(args->print));
		pthread_mutex_destroy(&(args->check));
		pthread_mutex_destroy(&(args->routine));
		return (-1);
	}
	return (0);
}

int	ft_args_init_mutex(t_args *args)
{
	int	i;

	if (ft_mutex_init(args))
		return (-1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philo_num);
	if (!(args->forks))
	{
		ft_mutex_destroy(args);
		return (1);
	}
	i = 0;
	while (i < args->philo_num)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (mutex_destroy_while_init(args, i));
		i++;
	}
	return (0);
}

int	ft_args_init(t_args *args, int argc, char *argv[])
{
	args->philo_num = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	args->start_time = ft_get_time();
	if (args->philo_num <= 0 || args->time_die < 0
		|| args->time_eat < 0 || args->time_sleep < 0)
		return (-1);
	if (argc == 6)
	{
		args->eat_must = ft_atoi(argv[5]);
		if (args->eat_must <= 0)
			return (1);
	}
	else
		args->eat_must = 0;
	if (ft_args_init_mutex(args))
		return (1);
	return (0);
}

int	ft_philo_init(t_philo **philo, t_args *args)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * args->philo_num);
	if (!(*philo))
		return (1);
	while (i < args->philo_num)
	{
		(*philo)[i].args = args;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % args->philo_num;
		(*philo)[i].last_eat_time = ft_get_time();
		(*philo)[i].eat_count = 0;
		i++;
	}
	return (0);
}
