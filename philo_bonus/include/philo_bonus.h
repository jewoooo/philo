/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:58:28 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/10 13:37:38 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>

# define SUCCESS 0
# define FAIL 1
# define TRUE 1
# define FALSE 0

typedef struct	s_info
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		must_eat;
}	t_info;

int		init_info(t_info **info, char **argv);
int		valid_argv(int argc, char **argv);
int		er_print(char *s);
int		ft_atoi(char *s);
long	ft_atol(char *s);
long	gettime(void);

#endif
