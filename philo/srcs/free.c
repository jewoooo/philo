/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:34:16 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 09:24:27 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	er_free_info(t_info **info)
{
	free(*info);
	*info = NULL;
	return (FAIL);
}

int	er_free_all(t_info **info, t_philo **philos, t_fork **forks)
{
	if (*forks != NULL)
	{
		free(*forks);
		*forks = NULL;
	}
	if (*philos != NULL)
	{
		free(*philos);
		*philos = NULL;
	}
	if (*info != NULL)
	{
		free(*info);
		*info = NULL;
	}
	return (FAIL);
}

void	free_all(t_info **info, t_philo **philos, t_fork **forks)
{
	if (*forks != NULL)
	{
		free(*forks);
		*forks = NULL;
	}
	if (*philos != NULL)
	{
		free(*philos);
		*philos = NULL;
	}
	if (*info != NULL)
	{
		free(*info);
		*info = NULL;
	}
}

void	destroy_mutex(t_info *info)
{
	int		i;
	t_philo	*philos;
	t_fork	*forks;

	philos = info->philos;
	forks = info->forks;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_destroy(&(forks[i].mutex));
		pthread_mutex_destroy(&(philos[i].count_mutex));
	}
	pthread_mutex_destroy(&(info->died_mutex));
	pthread_mutex_destroy(&(info->finished_mutex));
	pthread_mutex_destroy(&(info->print_mutex));
}
