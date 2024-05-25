/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:48:38 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/25 23:13:48 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*monitoring(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	usleep(philo->time_to_die / 2 * 1000);
	while (TRUE)
	{
		sem_wait(philo->last_sem);
		if (gettime() - philo->last_eat_time
			>= philo->time_to_die)
		{
			sem_post(philo->last_sem);
			exit(philo->id);
		}
		sem_post(philo->last_sem);
		usleep(500);
	}
	return (NULL);
}

void	create_thread(t_philo *philo)
{
	if (pthread_create(&(philo->monitor), NULL, &monitoring, philo) != 0)
		exit(FAIL);
	pthread_detach(philo->monitor);
}
