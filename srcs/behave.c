/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 16:28:11 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_fork(t_philo *philo, t_fork *fork)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(fork->mutex));
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d has taken a fork\n",
			gettime() - info->launch_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
	fork->taken = TRUE;
}

static void	put_fork(t_fork *fork)
{
	fork->taken = FALSE;
	pthread_mutex_unlock(&(fork->mutex));
}

void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	take_fork(philo, philo->right_fork);
	take_fork(philo, philo->left_fork);
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d is eating\n",
			gettime() - info->launch_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
	pthread_mutex_lock(&(philo->mutex));
	philo->eating = TRUE;
	usleep(info->time_to_eat * 1000);
	philo->last_eat_time = gettime();
	pthread_mutex_unlock(&(philo->mutex));
	put_fork(philo->left_fork);
	pthread_mutex_lock(&(philo->mutex));
	philo->eating = FALSE;
	pthread_mutex_unlock(&(philo->mutex));
	put_fork(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d is sleeping\n",
			gettime() - info->launch_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
	usleep(info->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d is thinking\n",
		gettime() - info->launch_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
}
