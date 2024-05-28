/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:42:09 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/28 23:40:47 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>

# define SUCCESS 0
# define FAIL 1
# define TRUE 1
# define FALSE 0
# define FINISHED 0

typedef struct s_philo
{
	int			id;
	char		*s_id;
	int			num_of_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			must_eat;
	int			count_eating;
	long		launch_time;
	long		last_eat_time;
	pid_t		*pid;
	pthread_t	monitor;
	sem_t		*forks_sem;
	sem_t		*print_sem;
	sem_t		*last_sem;
}	t_philo;

int		init_info(t_philo **philo, char **argv);
int		init_philo(t_philo **philo);
int		init_sem(t_philo **philo);
void	init_last_sem(t_philo *philo);

int		create_processes(t_philo *philo);
void	create_thread(t_philo *philo);
void	wait_child(t_philo *philo);

void	child_behave(t_philo *philo);

void	philo_sleep(long sleep_time);
void	philo_print(char *s, t_philo *philo);

int		valid_argv(int argc, char **argv);

int		check_died(t_philo *philo);
char	*ft_itoa(long n);
int		ft_atoi(char *s);
long	ft_atol(char *s);
long	gettime(void);

void	unlink_free(t_philo **philo);

int		er_print(char *s);
int		er_free_philo(t_philo **philo);
int		er_unlink_free(t_philo **philo);

#endif