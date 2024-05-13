/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:48:38 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/13 10:14:30 by jewlee           ###   ########.fr       */
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
		philo_print("died", philo);
		return (TRUE);
	}
	sem_post(philo->last_sem);
	sem_post(philo->die_sem);
	return (FALSE);
}

void	*monitoring(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	usleep(philo->time_to_die / 2 * 1000);
	while (TRUE)
	{
		if (check_dead(philo) == TRUE)
			exit(DIED_BY_TIME);
	}
	return (NULL);
}

void	create_thread(t_philo *philo)
{
	if (pthread_create(&(philo->monitor), NULL, &monitoring, philo) != 0)
		exit(FAIL_PTH);
	pthread_detach(philo->monitor);
}
