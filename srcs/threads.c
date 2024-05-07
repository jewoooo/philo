/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:40:15 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 16:27:59 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)args;
	info = philo->info;
	if (philo->id % 2 == 1)
		usleep(info->time_to_eat / 2 * 1000);
	while (TRUE)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (check_died(philo) == TRUE)
			break ;
	}
	return (NULL);
}

void	*monitoring(void *args)
{
	t_philo	*philos;
	t_info	*info;

	philos = (t_philo *)args;
	info = philos->info;
	usleep(info->time_to_eat * 1000);
	while (TRUE)
	{
		if (check_dead(philos) == TRUE ||
			(info->must_eat != -1
			&& check_all_philos_need(philos) == TRUE))
			break ;
	}
	return (NULL);
}

int	create_thread(t_info *info, t_philo *philos)
{
	pthread_t	monitor;
	int			i;

	if (pthread_create(&monitor, NULL, &monitoring, philos) != 0)
		return (FAIL);
	i = -1;
	while (++i < info->num_of_philos)
	{
		philos[i].last_eat_time = gettime();
		if (pthread_create(&((philos[i]).th), NULL, &philo_routine,  &(philos[i])) != 0)
			return (FAIL);
	}
	if (pthread_join(monitor, NULL) != 0)
		return (FAIL);
	i = -1;
	while (++i < info->num_of_philos)
	{
		if (pthread_join(philos[i].th, NULL) != 0)
			return (FAIL);
	}
	return (SUCCESS);
}
