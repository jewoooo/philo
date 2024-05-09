/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:34:16 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/10 00:25:29 by jewlee           ###   ########.fr       */
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
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->print_mutex));
}
