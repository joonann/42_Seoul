/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:26:27 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/30 05:50:15 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *argv)
{
	t_args	*args;
	t_philo	*philo;

	philo = argv;
	args = philo->args;
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&(args->check));
		if (args->finish)
		{
			pthread_mutex_unlock(&(args->check));
			break ;
		}
		pthread_mutex_unlock(&(args->check));
		ft_philo_action(args, philo);
		pthread_mutex_lock(&(args->routine));
		if (philo->eat_count == args->eat_must)
		{
			(args->finished_eat)++;
			pthread_mutex_unlock(&(args->routine));
			break ;
		}
		pthread_mutex_unlock(&(args->routine));
		ft_philo_printf(args, philo->id, "is sleeping");
		ft_pass_time((long long)args->time_sleep);
		ft_philo_printf(args, philo->id, "is thinking");
	}
	return (0);
}

int	ft_philo_action(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->forks[philo->left]));
	ft_philo_printf(args, philo->id, "has taken a fork");
	if (args->philo_num != 1)
	{
		pthread_mutex_lock(&(args->forks[philo->right]));
		ft_philo_printf(args, philo->id, "has taken a fork");
		ft_philo_printf(args, philo->id, "is eating");
		pthread_mutex_lock(&(args->pass_time));
		philo->last_eat_time = ft_get_time();
		(philo->eat_count)++;
		pthread_mutex_unlock(&(args->pass_time));
		ft_pass_time((long long)args->time_eat);
		pthread_mutex_unlock(&(args->forks[philo->right]));
	}
	pthread_mutex_unlock(&(args->forks[philo->left]));
	return (0);
}

void	ft_free_thread(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		i++;
	}
	free(philo);
	free(args->forks);
	ft_mutex_destroy(args);
}

void	ft_philo_finish_check(t_args *args, t_philo *philo)
{
	int			i;
	long long	now;

	while (1)
	{
		pthread_mutex_lock(&(args->check));
		if (args->finish)
		{
			pthread_mutex_unlock(&(args->check));
			break ;
		}
		pthread_mutex_unlock(&(args->check));
		pthread_mutex_lock(&(args->check));
		pthread_mutex_lock(&(args->routine));
		if ((args->eat_must != 0) && (args->philo_num == args->finished_eat))
			args->finish = 1;
		pthread_mutex_unlock(&(args->routine));
		pthread_mutex_unlock(&(args->check));
		i = 0;
		while (i < args->philo_num)
		{
			pthread_mutex_lock(&(args->check));
			if (args->finish)
			{
				pthread_mutex_unlock(&(args->check));
				break ;
			}
			pthread_mutex_unlock(&(args->check));
			now = ft_get_time();
			pthread_mutex_lock(&(args->pass_time));
			if ((now - philo[i].last_eat_time) >= args->time_die)
			{
				ft_philo_printf(args, i, "died");
				pthread_mutex_lock(&(args->check));
				args->finish = 1;
				pthread_mutex_unlock(&(args->check));
			}
			pthread_mutex_unlock(&(args->pass_time));
			i++;
		}
	}
}

int	ft_philo_start(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		philo[i].last_eat_time = ft_get_time();
		if (pthread_create(&(philo[i].thread), NULL, ft_routine, &(philo[i])))
			return (1);
		i++;
	}
	ft_philo_finish_check(args, philo);
	i = 0;
	while (i < args->philo_num)
		pthread_join(philo[i++].thread, NULL);
	ft_free_thread(args, philo);
	return (0);
}
