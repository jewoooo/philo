/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:18:25 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 10:50:33 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAIL 1
# define TRUE 1
# define FALSE 0

# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				count_meal;
	long			last_meal;
	struct s_info	*info;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	pthread_mutex_t	count_mutex;
	pthread_mutex_t	last_mutex;
}	t_philo;

typedef struct s_fork
{
	int				taken;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_info
{
	int				num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	int				died;
	int				finished;
	long			launch_time;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	finished_mutex;
}	t_info;

int		valid_argv(int argc, char **argv);

int		init_info(t_info **info, char **argv);
int		init_philos(t_info **info, t_philo **philos);
int		init_forks(t_info **info, t_philo **philos);
int		init_mutex(t_info **info, t_philo **philos);

int		er_print(char *s);
int		er_free_info(t_info **info);
int		er_free_all(t_info **info, t_philo **philos, t_fork **forks);
void	free_all(t_info **info, t_philo **philos, t_fork **forks);
void	destroy_mutex(t_info *info);

int		create_thread(t_info **info, t_philo **philos);
int		join_thread(t_info **info, t_philo **philos);

int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

void	one_philo_case(t_philo *philo);

int		philo_sleep(t_info *info, long sleep_time);
int		philo_print(char *s, t_philo *philo);

int		check_died(t_info *info);
int		check_died_flag(t_info *info);
int		check_all_finished(t_info *info);
int		check_finished_flag(t_info *info);

long	gettime(void);
int		ft_atoi(char *s);
long	ft_atol(char *s);

#endif