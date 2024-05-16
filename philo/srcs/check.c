/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 03:50:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 15:37:45 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
			philo_print("died", &(philos[i]));
			pthread_mutex_lock(&(info->died_mutex));
			info->died = TRUE;
			pthread_mutex_unlock(&(info->died_mutex));
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
