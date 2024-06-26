/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 03:50:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/26 12:42:23 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_started(t_info *info)
{
	pthread_mutex_lock(&(info->started_mutex));
	if (info->started == TRUE)
	{
		pthread_mutex_unlock(&(info->started_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->started_mutex));
	return (FALSE);
}

int	check_died_flag(t_info *info)
{
	pthread_mutex_lock(&(info->died_mutex));
	if (info->died == TRUE)
	{
		pthread_mutex_unlock(&(info->died_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->died_mutex));
	return (FALSE);
}

int	check_died(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = info->philos;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].last_mutex));
		if (gettime() - philos[i].last_meal >= info->time_to_die)
		{
			pthread_mutex_unlock(&(philos[i].last_mutex));
			pthread_mutex_lock(&(info->died_mutex));
			info->died = TRUE;
			pthread_mutex_unlock(&(info->died_mutex));
			pthread_mutex_lock(&(info->print_mutex));
			printf("%ld %d died\n", gettime() - info->launch_time,
				philos[i].id);
			pthread_mutex_unlock(&(info->print_mutex));
			return (TRUE);
		}
		pthread_mutex_unlock(&(philos[i].last_mutex));
	}
	return (FALSE);
}

int	check_finished_flag(t_info *info)
{
	if (info->must_eat <= 0)
		return (FALSE);
	pthread_mutex_lock(&(info->finished_mutex));
	if (info->finished == TRUE)
	{
		pthread_mutex_unlock(&(info->finished_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->finished_mutex));
	return (FALSE);
}

int	check_all_finished(t_info *info)
{
	t_philo	*philos;
	int		i;
	int		cnt;

	if (info->must_eat < 0)
		return (FALSE);
	philos = info->philos;
	i = -1;
	cnt = 0;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].count_mutex));
		if (philos[i].count_meal >= info->must_eat)
			cnt++;
		pthread_mutex_unlock(&(philos[i].count_mutex));
	}
	if (cnt == info->num_of_philos)
	{
		pthread_mutex_lock(&(info->finished_mutex));
		info->finished = TRUE;
		pthread_mutex_unlock(&(info->finished_mutex));
		return (TRUE);
	}
	return (FALSE);
}
