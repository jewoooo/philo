/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 03:50:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 16:27:37 by jewlee           ###   ########.fr       */
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

/*
Description : Check for philo's dead by time to die
*/

int	check_dead(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos->info;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].mutex));
		if (gettime() - philos[i].last_eat_time >= info->time_to_die)
		{
			pthread_mutex_lock(&(info->print_mutex));
			printf("%ld %d died\n",
				gettime() - info->launch_time, philos[i].id);
			pthread_mutex_unlock(&(info->print_mutex));
			pthread_mutex_lock(&(info->die_mutex));
			info->died = TRUE;
			pthread_mutex_unlock(&(info->die_mutex));
			pthread_mutex_unlock(&(philos[i].mutex));
			return (TRUE);
		}
		pthread_mutex_unlock(&(philos[i].mutex));
	}
	return (FALSE);
}

int	check_all_philos_need(t_philo *philos)
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
		pthread_mutex_lock(&(philos[i].mutex));
		if (philos[i].count_eating >= info->must_eat)
			count++;
		pthread_mutex_unlock(&(philos[i].mutex));
	}
	if (count == info->num_of_philos)
	{
		pthread_mutex_lock(&(info->die_mutex));
		info->died = TRUE;
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	return (FALSE);
}
