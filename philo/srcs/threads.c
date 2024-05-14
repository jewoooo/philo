/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:40:15 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/14 16:13:29 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)args;
	info = philo->info;
	while (TRUE)
		if (check_created(info) == TRUE)
			break ;
	if (philo->id % 2 == 1 && info->num_of_philos != 1)
		usleep(info->time_to_eat / 2 * 1000);
	while (TRUE)
	{
		if (check_died(philo) == TRUE
			|| eating(philo) == FAIL
			|| check_finished(philo) == TRUE)
			break ;
		if (check_died(philo) == TRUE || check_finished(philo) == TRUE)
			break ;
		sleeping(philo);
		if (check_died(philo) == TRUE || check_finished(philo) == TRUE)
			break ;
		thinking(philo);
	}
	return (NULL);
}

void	*monitoring(void *args)
{
	t_philo	*philos;
	t_info	*info;

	info = (t_info *)args;
	philos = info->philos;
	if (info->num_of_philos != 1)
		usleep(info->time_to_die / 2 * 1000);
	while (TRUE)
	{
		if (check_dead(philos) == TRUE)
			break ;
		if (info->must_eat != -1
			&& check_all_satisfied(philos) == TRUE)
		{
			pthread_mutex_lock(&(info->finished_mutex));
			info->finished = TRUE;
			pthread_mutex_unlock(&(info->finished_mutex));
		}
	}
	return (NULL);
}

int	create_thread(t_info **info, t_philo **philos)
{
	int	i;

	pthread_mutex_lock(&((*info)->start_mutex));
	i = -1;
	while (++i < (*info)->num_of_philos)
	{
		(*philos)[i].last_eat_time = gettime();
		if (pthread_create(&((*philos)[i].th), NULL,
			&philo_routine, &((*philos)[i])) != 0)
			return (er_free_all(info, philos, &((*info)->forks)));
	}
	(*info)->created = TRUE;
	pthread_mutex_unlock(&((*info)->start_mutex));
	if (pthread_create(&((*info)->monitor), NULL, &monitoring, *info) != 0)
		return (er_free_all(info, philos, &((*info)->forks)));
	return (SUCCESS);
}

int	join_thread(t_info **info, t_philo **philos)
{
	int	i;

	i = -1;
	pthread_detach((*info)->monitor);
	while (++i < (*info)->num_of_philos)
	{
		if (pthread_join((*philos)[i].th, NULL) != 0)
			return (er_free_all(info, philos, &((*info)->forks)));
	}
	// if (pthread_join((*info)->monitor, NULL) != 0)
	// 	return (er_free_all(info, philos, &((*info)->forks)));
	return (SUCCESS);
}
