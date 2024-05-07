/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:34:16 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 16:19:46 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(t_philo **philos, t_fork **forks)
{
	if (*philos != NULL)
		free(*philos);
	if (*forks != NULL)
		free(*forks);
}

void	destroy_mutex(t_info *info, t_philo *philos)
{
	int		i;
	t_fork	*forks;

	forks = info->forks;
	i = -1;
	while (++i < info->num_of_philos)
	{
		pthread_mutex_destroy(&(philos[i].mutex));
		pthread_mutex_destroy(&(forks[i].mutex));
	}
	pthread_mutex_destroy(&(info->mutex));
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->print_mutex));
}
