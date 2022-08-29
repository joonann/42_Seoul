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
	int	philo_num;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	eat_must;
	int	finish;
	int	finished_eat;
	long long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_args;

typedef struct s_philo
{
	struct s_args	*args;
	pthread_t	thread;
	int	id;
	int	left;
	int	right;
	long long	last_eat_time;
	int	eat_count;
}	t_philo;

int	print_error(char *msg, int errno);
long long	ft_get_time(void);
int	mutex_destroy_while_init(t_args *args, int index);
int	ft_args_init_mutex(t_args *args);
int	ft_args_init(t_args *args, int argc, char *argv[]);
int	ft_philo_init(t_philo **philo, t_args *args);
int	error_free(char *msg, int errno, t_args *args, t_philo **philo);
int	error_destroy(char *msg, int errno, t_args *args, t_philo **philo);
void	ft_pass_time(long long wait_time, t_args *args);
void	*ft_routine(void *argv);
int	ft_philo_printf(t_args *args, int id, char *msg);
int	ft_philo_action(t_args *args, t_philo *philo);
void	ft_free_thread(t_args *args, t_philo *philo);
void	ft_philo_finish_check(t_args *args, t_philo *philo);
int	ft_philo_start(t_args *args, t_philo *philo);
int	ft_atoi(char *str);

#endif