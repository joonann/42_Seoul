/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:09:16 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/30 06:05:07 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_must;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
	pthread_mutex_t	routine;
	pthread_mutex_t	pass_time;
	pthread_mutex_t	death;
}	t_args;

typedef struct s_philo
{
	struct s_args	*args;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}	t_philo;

int			print_error(char *msg);
long long	ft_get_time(void);
int			mutex_destroy_while_init(t_args *args, int index);
int			ft_args_init_mutex(t_args *args);
int			ft_args_init(t_args *args, int argc, char *argv[]);
int			ft_philo_init(t_philo **philo, t_args *args);
int			error_free(char *msg, t_args *args, t_philo **philo);
int			error_destroy(char *msg, t_args *args, t_philo **philo);
void		ft_pass_time(long long wait_time);
void		*ft_routine(void *argv);
int			ft_philo_printf(t_args *args, int id, char *msg);
int			ft_philo_action(t_args *args, t_philo *philo);
void		ft_free_thread(t_args *args, t_philo *philo);
void		ft_philo_finish_check(t_args *args, t_philo *philo);
int			ft_philo_start(t_args *args, t_philo *philo);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_mutex_init(t_args *args);
int			ft_mutex_destroy(t_args *args);
void		ft_check_dead(t_args *args, t_philo *philo, int *i, long long *now);
void		ft_routine_sub_1(t_args *args, t_philo *philo);
void		ft_routine_sub_2(t_args *args, t_philo *philo);

#endif
