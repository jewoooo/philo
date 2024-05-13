/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 03:50:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/13 16:32:51 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_finished(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (info->must_eat == (-1))
		return (FALSE);
	if (info->must_eat > philo->count_eating)
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

int	check_died(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (gettime() - philo->last_eat_time >= info->time_to_die)
	{
		philo_print("died", philo);
		pthread_mutex_lock(&(info->die_mutex));
		info->died = TRUE;
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	return (FALSE);
}

int	check_dead(t_philo *philos)
{
	t_info	*info;

	info = philos->info;
	pthread_mutex_lock(&(info->die_mutex));
	if (info->died == TRUE)
	{
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->die_mutex));
	return (FALSE);
}

void	check_satisfied(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (info->must_eat + 1 <= philo->count_eating)
		return ;
	if (info->must_eat <= philo->count_eating)
	{
		pthread_mutex_lock(&(info->satis_mutex));
		(info->satisfied)[philo->id - 1] = TRUE;
		pthread_mutex_unlock(&(info->satis_mutex));
	}
}

int	check_all_satisfied(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos->info;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_lock(&(info->satis_mutex));
		if (info->satisfied[i] == FALSE)
		{
			pthread_mutex_unlock(&(info->satis_mutex));
			return (FALSE);
		}
		pthread_mutex_unlock(&(info->satis_mutex));
	}
	return (TRUE);
}
