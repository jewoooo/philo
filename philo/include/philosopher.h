/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:50:40 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/29 09:49:16 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAIL 1
# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				start_time; // for check time
	int				last_eating; // for time to die
	int				count_of_eating;
	struct s_info	*info;
	struct s_fork	*l_fork;
	struct s_fork	*r_fork;
}	t_philo;

typedef struct s_fork
{
	int				id;
	int				taken;
	pthread_mutex_t	mutex;
}	t_fork;


typedef struct	s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				died;
	long			start_time;
	struct s_fork	*fork;
	struct s_philo	*philos;
}	t_info;

int	ft_atoi(char *s);

int	free_all(t_info *info);

int	valid_argv(char *s);
int	valid_args(char **argv);

int	init_info(t_info *info, char **argv);
int	init_philo(t_info *info, t_philo **philos);
int	init_fork(t_info *info, t_philo **philos);

#endif