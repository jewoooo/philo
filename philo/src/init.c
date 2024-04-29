/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:52:42 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/29 11:00:04 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	init_info(t_info *info, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	return (SUCCESS);
}

int	init_philo(t_info *info, t_philo **philos)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (*philos == NULL)
		return (FAIL);
	memset(*philos, 0, sizeof(t_philo) * info->num_of_philo);
	i = -1;
	while (++i < info->num_of_philo)
	{
		(*philos)->id = i + 1;
		(*philos)->count_of_eating = 0;
		(*philos)->start_time = 0;
		(*philos)->last_eating = 0;
	}
	return (SUCCESS);
}

int	init_fork(t_info *info, t_philo **philos)
{
	int	i;

	info->fork = (t_fork *)malloc(sizeof(t_fork) * info->num_of_philo);
	if (info->fork == NULL)
		return (FAIL);
	memset(info->fork, 0, sizeof(t_fork) * info->num_of_philo);
	if (pthread_mutex_init(info->print_mutex, NULL) != 0)
		return (FAIL);
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->fork[i].id = i + 1;
		info->fork[i].taken = FALSE;
		if (pthread_mutex_init(&(info->fork[i].mutex), NULL) != 0)
			return (FAIL);
		(*philos)[i].l_fork = info->fork[i];
		if (i == info->num_of_philo - 1)
			(*philos)[i].r_fork = info->fork[0];
		else
			(*philos)[i].r_fork = info->fork[i + 1];
	}
	return (SUCCESS);
}
