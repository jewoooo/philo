/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:18:25 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 14:48:32 by jewlee           ###   ########.fr       */
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
	int				count_eating;
	long			last_eat_time;
	int				eating;
	struct s_info	*info;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	pthread_mutex_t	mutex;
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
	long			launch_time;
	t_philo			*philos;
	pthread_t		monitoring;
	t_fork			*forks;
	pthread_mutex_t	mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	print_mutex;
}	t_info;

int		valid_argv(int argc, char **argv);

int		init_info(t_info *info, char **argv);
int		init_philos(t_info *info, t_philo **philos);
int		init_fork(t_info *info, t_philo *philos);
int		init_mutex(t_info *info, t_philo *philos);

void	free_all(t_philo **philos, t_fork **forks);
void	destroy_mutex(t_info *info, t_philo *philos);

int		create_thread(t_info *info, t_philo *philos);

void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

int		check_died(t_philo *philo);
int		check_dead(t_philo *philos);
int		check_all_philos_need(t_philo *philos);

long	gettime(void);
int		ft_atoi(char *s);
long	ft_atol(char *s);

#endif