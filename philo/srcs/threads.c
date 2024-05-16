/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:40:15 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 16:12:10 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	reset_last_meal(philo);
	if (philo->id % 2 == 0 && philo->info->num_of_philos != 1)
		usleep(philo->info->time_to_eat * 1000);
	while (TRUE)
	{
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		if (eating(philo) == FAIL)
			break ;
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		sleeping(philo);
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		thinking(philo);
	}
	return (NULL);
}

void	*monitoring(void *args)
{
	t_info	*info;

	info = (t_info *)args;
	if (info->num_of_philos != 1)
		usleep(info->time_to_die / 2 * 1000);
	while (TRUE)
		if (check_died(info) == TRUE || check_all_finished(info) == TRUE)
			break ;
	return (NULL);
}

int	create_thread(t_info **info, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < (*info)->num_of_philos)
	{
		if (pthread_create(&((*philos)[i].th), NULL,
			&philo_routine, &((*philos)[i])) != 0)
			return (er_free_all(info, philos, &((*info)->forks)));
	}
	if (pthread_create(&((*info)->monitor), NULL, &monitoring, *info) != 0)
		return (er_free_all(info, philos, &((*info)->forks)));
	return (SUCCESS);
}

int	join_thread(t_info **info, t_philo **philos)
{
	int	i;

	if (pthread_join((*info)->monitor, NULL) != 0)
		return (er_free_all(info, philos, &((*info)->forks)));
	i = -1;
	while (++i < (*info)->num_of_philos)
	{
		if (pthread_join((*philos)[i].th, NULL) != 0)
			return (er_free_all(info, philos, &((*info)->forks)));
	}
	return (SUCCESS);
}
