#include "philo.h"

int	print_error(char *msg, int errno)
{
	printf("%s : %d\n", msg, errno);
	return (errno);
}

long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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

int	ft_args_init_mutex(t_args *args)
{
	int	i;

	if (pthread_mutex_init(&(args->print), NULL))
		return (1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philo_num);
	if (!(args->forks))
	{
		pthread_mutex_destroy(&(args->print));
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
		return (5);
	if (argc == 6)
	{
		args->eat_must = ft_atoi(argv[5]);
		if (args->eat_must <= 0)
			return (6);
	}
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

int	error_free(char *msg, int errno, t_args *args, t_philo **philo)
{
	if (args->forks)
		free(args->forks);
	if (*philo)
		free(*philo);
	return (print_error(msg, errno));
}

int	error_destroy(char *msg, int errno, t_args *args, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->print));
	return(error_free(msg, errno, args, philo));
}

void	ft_pass_time(long long wait_time, t_args *args)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (!(args->finish))
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

void	*ft_routine(void *argv)
{
	t_args	*args;
	t_philo	*philo;

	philo = argv;
	args = philo->args;
	if (philo->id % 2)
		usleep(1000);
	else
		usleep(500);
	while (!args->finish)
	{
		ft_philo_action(args, philo);
		if (philo->eat_count == args->eat_must)
		{
			(args->finished_eat)++;
			break ;
		}
		ft_philo_printf(args, philo->id, "is sleeping");
		ft_pass_time((long long)args->time_sleep, args);
		ft_philo_printf(args, philo->id, "is thinking");
	}
	return (0);
}

int	ft_philo_printf(t_args *args, int id, char *msg)
{
	long long	now;

	now = ft_get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(args->print));
	if (!(args->finish))
		printf("%lld %d %s\n", now - args->start_time, id + 1, msg);
	pthread_mutex_unlock(&(args->print));
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
		philo->last_eat_time = ft_get_time();
		(philo->eat_count)++;
		ft_pass_time((long long)args->time_eat, args);
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
	pthread_mutex_destroy(&(args->print));
}

void	ft_philo_finish_check(t_args *args, t_philo *philo)
{
	int	i;
	long long	now;

	while (!args->finish)
	{
		if ((args->eat_must != 0) && (args->philo_num == args->finished_eat))
		{
			args->finish = 1;
			break ;
		}
		i = 0;
		while (i < args->philo_num)
		{
			now = ft_get_time();
			if ((now - philo[i].last_eat_time) >= args->time_die)
			{
				ft_philo_printf(args, i, "died");
				args->finish = 1;
				break ;
			}
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	long long	result;
	int	sign;
	int	check;

	result = 0;
	sign = 1;
	check = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		check++;
		if ((result < 0 || check > 19) && sign == 1)
			return (-1);
		else if ((result < 0 || check > 19) && sign == -1)
			return (-1);
		str++;
	}
	return (result * sign);
}

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philo;
	int	errno;

	memset(&args, 0, sizeof(t_args));
	errno = 0;
	if (argc != 5 && argc != 6)
		return (print_error("wrong argument", 3));
	else
		errno = ft_args_init(&args, argc, argv);
	if (errno)
		return (error_free("args init error", errno, &args, &philo));
	errno = ft_philo_init(&philo, &args);
	if (errno)
		return (error_destroy("philosophers init", errno, &args, &philo));
	errno = ft_philo_start(&args, philo);

}