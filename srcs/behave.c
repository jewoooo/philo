/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/10 00:26:53 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	if (fork->taken == FALSE)
	{
		fork->taken = TRUE;
		philo_print("has taken a fork", philo);
	}
}

static void	put_fork(t_fork *fork)
{
	fork->taken = FALSE;
	pthread_mutex_unlock(&(fork->mutex));
}

int	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	take_fork(philo, philo->left_fork);
	if (info->num_of_philos == 1)
	{
		while (check_died(philo) == FALSE);
		put_fork(philo->left_fork);
		return (FAIL);
	}
	take_fork(philo, philo->right_fork);
	if (philo_print("is eating", philo) == FAIL ||
		philo_sleep(gettime(), info->time_to_eat, philo) == FAIL)
	{
		put_fork(philo->right_fork);
		put_fork(philo->left_fork);
		return (FAIL);
	}
	pthread_mutex_lock(&(philo->count_mutex));
	philo->count_eating += 1;
	pthread_mutex_unlock(&(philo->count_mutex));
	reset_last_eat_time(philo);
	put_fork(philo->right_fork);
	put_fork(philo->left_fork);
	return (SUCCESS);
}

int	sleeping(t_philo *philo)
{
	if (philo_print("is sleeping", philo) == FAIL)
		return (FAIL);
	if (philo_sleep(gettime(), philo->info->time_to_sleep, philo) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (philo_print("is thinking", philo) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
