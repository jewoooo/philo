/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/14 13:52:46 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->taken = TRUE;
	philo_print("has taken a fork", philo);
}

void	put_fork(t_fork *fork)
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
		one_philo_case(philo);
		return (FAIL);
	}
	take_fork(philo, philo->right_fork);
	philo_print("is eating", philo);
	philo->last_eat_time = gettime();
	philo_sleep(gettime(), info->time_to_eat);
	put_fork(philo->right_fork);
	philo->count_eating += 1;
	if (info->must_eat != (-1))
		check_satisfied(philo);
	put_fork(philo->left_fork);
	return (SUCCESS);
}

void	sleeping(t_philo *philo)
{
	philo_print("is sleeping", philo);
	philo_sleep(gettime(), philo->info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	philo_print("is thinking", philo);
}
