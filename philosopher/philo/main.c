/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:25:21 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/30 05:36:12 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_pass_time(long long wait_time)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (1)
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}

int	ft_philo_printf(t_args *args, int id, char *msg)
{
	long long	now;

	now = ft_get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(args->check));
	pthread_mutex_lock(&(args->print));
	if (!(args->finish))
		printf("%lld %d %s\n", now - args->start_time, id + 1, msg);
	pthread_mutex_unlock(&(args->print));
	pthread_mutex_unlock(&(args->check));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philo;
	int		check_zero;

	memset(&args, 0, sizeof(t_args));
	check_zero = 0;
	if (argc != 5 && argc != 6)
		return (print_error("wrong argument"));
	else
		check_zero = ft_args_init(&args, argc, argv);
	if (check_zero < 0)
		return (print_error("wrong argument"));
	else if (check_zero)
		return (error_free("args init error", &args, &philo));
	check_zero = ft_philo_init(&philo, &args);
	if (check_zero)
		return (error_destroy("philosophers init", &args, &philo));
	check_zero = ft_philo_start(&args, philo);
	if (check_zero)
		return (error_destroy("thread create fail", &args, &philo));
	return (0);
}
