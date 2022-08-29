/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 06:16:27 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/30 06:17:27 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine_sub_1(t_args *args, t_philo *philo)
{
	pthread_mutex_unlock(&(args->check));
	ft_philo_action(args, philo);
	pthread_mutex_lock(&(args->routine));
}

void	ft_routine_sub_2(t_args *args, t_philo *philo)
{
	pthread_mutex_unlock(&(args->routine));
	ft_philo_printf(args, philo->id, "is sleeping");
	ft_pass_time((long long)args->time_sleep);
	ft_philo_printf(args, philo->id, "is thinking");
}

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
		ft_routine_sub_1(args, philo);
		if (philo->eat_count == args->eat_must)
		{
			(args->finished_eat)++;
			pthread_mutex_unlock(&(args->routine));
			break ;
		}
		ft_routine_sub_2(args, philo);
	}
	return (0);
}
