/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:37 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/30 18:40:02 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define SUCCESS 0
# define FAIL 1
# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int			num;
	int			left;
	int			right;
	pthread_t	thread;
}	t_philo;

typedef struct s_infos
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_times_must_eat;
}	t_infos;

int	atoi_for_philo(const char *s);

int valid_digit(char *s);
int	valid_argv(char *s);

int	init_infos(int argc, char **argv, t_infos *infos);

#endif