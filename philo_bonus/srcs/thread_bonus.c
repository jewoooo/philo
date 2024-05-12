/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:48:38 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/12 23:16:12 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	check_dead(t_philo *philo)
{
	sem_wait(philo->die_sem);
	sem_wait(philo->last_sem);
	if (gettime() - philo->last_eat_time
		>= philo->time_to_die)
	{
		sem_post(philo->last_sem);
		sem_post(philo->die_sem);
		philo_print("is died", philo);
		return (TRUE);
	}
	sem_post(philo->last_sem);
	sem_post(philo->die_sem);
	return (FALSE);
}

int	check_philo_eating(t_philo *philo)
{
	sem_wait(philo->count_sem);
	if (philo->count_eating >= philo->must_eat)
	{
		sem_post(philo->count_sem);
		return (TRUE);
	}
	sem_post(philo->count_sem);
	return (FALSE);
}

void	*monitoring(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (TRUE)
	{
		if (check_dead(philo) == TRUE)
			exit(DIED_BY_TIME);
		if (check_philo_eating(philo) == TRUE)
			exit(FINISHED_MEALS);
	}
	return (NULL);
}

void	create_thread(t_philo *philo)
{
	pthread_create(&(philo->monitor), NULL, &monitoring, philo);
	pthread_detach(philo->monitor);
}
