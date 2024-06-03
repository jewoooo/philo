/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:27:16 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/03 23:08:25 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->forks_sem);
	philo_print("has taken a fork", philo);
	sem_wait(philo->forks_sem);
	philo_print("has taken a fork", philo);
	philo_print("is eating", philo);
	sem_wait(philo->last_sem);
	philo->last_eat_time = gettime();
	sem_post(philo->last_sem);
	if (philo->must_eat > 0)
		philo->count_eating += 1;
	philo_sleep(philo->time_to_eat);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
}

void	sleeping(t_philo *philo)
{
	philo_print("is sleeping", philo);
	philo_sleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	philo_print("is thinking", philo);
}

void	child_behave(t_philo *philo)
{
	if (philo->num_of_philos > 1 && philo->id % 2 == 1)
		usleep(philo->time_to_eat * 1000);
	while (TRUE)
	{
		eating(philo);
		if (philo->must_eat > 0
			&& philo->count_eating >= philo->must_eat)
			exit(FINISHED);
		sleeping(philo);
		thinking(philo);
	}
}
