/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/09 12:13:34 by jewlee           ###   ########.fr       */
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
	long	start;
	t_info	*info;

	info = philo->info;
	take_fork(philo, philo->left_fork);
	if (info->num_of_philos == 1)
	{
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (FAIL);
	}
	take_fork(philo, philo->right_fork);
	if (philo_print("is eating", philo) == FAIL)
		return (FAIL);
	pthread_mutex_lock(&(philo->count_mutex));
	philo->count_eating += 1;
	pthread_mutex_unlock(&(philo->count_mutex));
	start = gettime();
	while (gettime() - start < info->time_to_eat)
	{
		if (check_died(philo) == TRUE)
			break ;
	}
	pthread_mutex_lock(&(philo->time_mutex));
	philo->last_eat_time = gettime();
	pthread_mutex_unlock(&(philo->time_mutex));
	put_fork(philo->right_fork);
	put_fork(philo->left_fork);
	return (SUCCESS);
}

int	sleeping(t_philo *philo)
{
	long	start;
	t_info	*info;

	info = philo->info;
	if (philo_print("is sleeping", philo) == FAIL)
		return (FAIL);
	start = gettime();
	while (gettime() - start < info->time_to_sleep)
	{
		if (check_died(philo) == TRUE)
			break ;
	}
	return (SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (philo_print("is thinking", philo) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
