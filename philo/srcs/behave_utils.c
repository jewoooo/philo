/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:52:56 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/24 20:35:11 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	one_philo_case(t_philo *philo)
{
	while (TRUE)
	{
		if (check_died_flag(philo->info) == TRUE)
			break ;
	}
}

void	philo_print(char *s, t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	if (check_died_flag(info) != TRUE)
	{
		printf("%ld %d %s\n", gettime() - info->launch_time,
			philo->id, s);
	}
	pthread_mutex_unlock(&(info->print_mutex));
}

void	philo_sleep(long sleep_time, t_info *info)
{
	long	start;

	start = gettime();
	while (TRUE)
	{
		if (gettime() - start >= sleep_time
			|| check_died_flag(info) == TRUE)
			break ;
		usleep(500);
	}
}

void	reset_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&(philo->last_mutex));
	philo->last_meal = gettime();
	pthread_mutex_unlock(&(philo->last_mutex));
}

void	reset_count_meal(t_philo *philo)
{
	pthread_mutex_lock(&(philo->count_mutex));
	philo->count_meal += 1;
	pthread_mutex_unlock(&(philo->count_mutex));
}
