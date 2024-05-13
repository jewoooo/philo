/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:52:56 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/13 10:08:32 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	one_philo_case(t_philo *philo)
{
	while (TRUE)
	{
		if (check_died(philo) == TRUE)
			break ;
	}
	put_fork(philo->left_fork);
}

int	philo_print(char *s, t_philo *philo)
{
	t_info	*info;

	if (check_died(philo) == TRUE)
		return (FAIL);
	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d %s\n", gettime() - info->launch_time,
		philo->id, s);
	pthread_mutex_unlock(&(info->print_mutex));
	return (SUCCESS);
}

int	philo_sleep(long start, long sleep_time, t_philo *philo)
{
	while (gettime() - start < sleep_time)
	{
		if (check_died(philo) == TRUE)
			return (FAIL);
	}
	return (SUCCESS);
}

void	reset_last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&(philo->time_mutex));
	philo->last_eat_time = gettime();
	pthread_mutex_unlock(&(philo->time_mutex));
}
