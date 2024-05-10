/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 03:50:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/10 12:57:43 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_died(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->die_mutex));
	if (info->died == TRUE)
	{
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->die_mutex));
	return (FALSE);
}

int	check_dead(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos->info;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].time_mutex));
		if (gettime() - philos[i].last_eat_time >= info->time_to_die)
		{
			pthread_mutex_unlock(&(philos[i].time_mutex));
			philo_print("died", &(philos[i]));
			return (TRUE);
		}
		pthread_mutex_unlock(&(philos[i].time_mutex));
	}
	return (FALSE);
}

int	check_all_philos_eating(t_philo *philos)
{
	t_info	*info;
	int		i;
	int		count;

	info = philos->info;
	if (info->must_eat == (-1))
		return (FALSE);
	count = 0;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].count_mutex));
		if (philos[i].count_eating >= info->must_eat)
			count++;
		pthread_mutex_unlock(&(philos[i].count_mutex));
	}
	if (count == info->num_of_philos)
		return (TRUE);
	return (FALSE);
}
