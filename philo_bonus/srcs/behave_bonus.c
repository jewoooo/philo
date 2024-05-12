/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:27:16 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/12 23:39:34 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	eating(t_philo *philo)
{
	long	start;

	sem_wait(philo->forks_sem);
	philo_print("has taken a fork", philo);
	sem_wait(philo->forks_sem);
	philo_print("has taken a fork", philo);
	philo_print("is eating", philo);
	start = gettime();
	while (gettime() - start < philo->time_to_eat);
	sem_wait(philo->last_sem);
	philo->last_eat_time = gettime();
	sem_post(philo->last_sem);
	sem_wait(philo->count_sem);
	philo->count_eating += 1;
	sem_post(philo->count_sem);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
}

void	sleeping(t_philo *philo)
{
	long	start;

	philo_print("is sleeping", philo);
	start = gettime();
	while (gettime() - start < philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	philo_print("is thinking", philo);
}

void	child_behave(t_philo *philo)
{
	if (philo->id % 2 == 1)
		usleep(philo->time_to_eat / 4 * 1000);
	while (TRUE)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
