/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:48:38 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/11 23:49:16 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	check_dead(t_philo *philo)
{
	sem_wait(philo->last_sem);
	if (gettime() - philo->last_eat_time
		>= philo->time_to_die)
	{
		sem_post(philo->last_sem);
		return (TRUE);
	}
	return (FALSE);
}

void	*monitoring(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (TRUE)
	{
		if (check_dead(philo) == TRUE)
			break ;
	}
	philo_print("is died", philo);
	exit(FAIL);
	return (NULL);
}

void	create_thread(t_philo **philo)
{
	pthread_create((*philo)->monitor, NULL, &monitoring, philo);
	pthread_detach((*philo)->monitor);
}
