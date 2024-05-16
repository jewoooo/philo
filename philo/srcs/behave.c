/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 10:48:37 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->taken = TRUE;
	philo_print("has taken a fork", philo);
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
	if (check_died_flag(info) == TRUE || check_finished_flag(info) == TRUE)
		return (FAIL);
	take_fork(philo, philo->left_fork);
	if (info->num_of_philos == 1)
	{
		one_philo_case(philo);
		put_fork(philo->left_fork);
		return (FAIL);
	}
	take_fork(philo, philo->right_fork);
	philo_print("is eating", philo);
	if (philo_sleep(info, info->time_to_eat) == FAIL)
	{
		put_fork(philo->right_fork);
		put_fork(philo->left_fork);
		return (FAIL);
	}
	philo->last_meal = gettime();
	philo->count_meal += 1;
	put_fork(philo->right_fork);
	put_fork(philo->left_fork);
	return (SUCCESS);
}

int	sleeping(t_philo *philo)
{
	if (check_died_flag(philo->info) == TRUE || check_finished_flag(philo->info) == TRUE)
		return (FAIL);
	philo_print("is sleeping", philo);
	philo_sleep(philo->info, philo->info->time_to_sleep);
	return (SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (check_died_flag(philo->info) == TRUE || check_finished_flag(philo->info) == TRUE)
		return (FAIL);
	philo_print("is thinking", philo);
	return (SUCCESS);
}
