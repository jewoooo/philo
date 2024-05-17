/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:40:15 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/17 18:31:06 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (TRUE)
		if (check_started_flag(philo->info) == TRUE)
			break ;
	reset_last_meal(philo);
	if (philo->id % 2 == 0 && philo->info->num_of_philos != 1)
		even_behave(philo);
	else
		odd_behave(philo);
	return (NULL);
}

void	*monitoring(void *args)
{
	t_info	*info;

	info = (t_info *)args;
	while (TRUE)
		if (check_started_flag(info) == TRUE)
			break ;
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
	pthread_mutex_lock(&((*info)->started_mutex));
	while (++i < (*info)->num_of_philos)
	{
		if (pthread_create(&((*philos)[i].th), NULL,
			&philo_routine, &((*philos)[i])) != 0)
			return (er_free_all(info, philos, &((*info)->forks)));
	}
	(*info)->started = TRUE;
	(*info)->launch_time = gettime();
	pthread_mutex_unlock(&((*info)->started_mutex));
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
