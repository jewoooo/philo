/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:50:41 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/26 12:42:37 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_info **info, t_philo **philos)
{
	t_fork	*forks;
	int		i;

	forks = (*info)->forks;
	if (pthread_mutex_init(&((*info)->died_mutex), NULL) != 0
		|| pthread_mutex_init(&((*info)->print_mutex), NULL) != 0
		|| pthread_mutex_init(&((*info)->finished_mutex), NULL) != 0
		|| pthread_mutex_init(&((*info)->started_mutex), NULL) != 0)
		return (er_free_all(info, philos, &forks));
	i = -1;
	while (++i < (*info)->num_of_philos)
	{
		if (pthread_mutex_init(&(forks[i].mutex), NULL) != 0
			|| pthread_mutex_init(&((*philos)[i].count_mutex), NULL) != 0
			|| pthread_mutex_init(&((*philos)[i].last_mutex), NULL) != 0)
			return (er_free_all(info, philos, &forks));
	}
	return (SUCCESS);
}

int	init_forks(t_info **info, t_philo **philos)
{
	int		i;
	t_fork	*forks;

	forks = malloc(sizeof(t_fork) * (*info)->num_of_philos);
	if (forks == NULL)
	{
		free(*info);
		free(*philos);
		return (FAIL);
	}
	memset(forks, 0, sizeof(t_fork) * (*info)->num_of_philos);
	i = -1;
	while (++i < (*info)->num_of_philos)
	{
		(*philos)[i].left_fork = &(forks[i]);
		if ((*info)->num_of_philos == 1)
			(*philos)[i].right_fork = NULL;
		else
			(*philos)[i].right_fork = &(forks[(i + 1)
					% (*info)->num_of_philos]);
	}
	(*info)->forks = forks;
	return (SUCCESS);
}

int	init_philos(t_info **info, t_philo **philos)
{
	int			i;

	*philos = malloc(sizeof(t_philo) * (*info)->num_of_philos);
	if (*philos == NULL)
		return (er_free_info(info));
	memset(*philos, 0, sizeof(t_philo) * (*info)->num_of_philos);
	i = -1;
	while (++i < (*info)->num_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].info = (*info);
	}
	(*info)->philos = (*philos);
	return (SUCCESS);
}

int	init_info(t_info **info, char **argv)
{
	*info = malloc(sizeof(t_info));
	if (*info == NULL)
		return (FAIL);
	memset(*info, 0, sizeof(t_info));
	(*info)->num_of_philos = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atol(argv[2]);
	(*info)->time_to_eat = ft_atol(argv[3]);
	(*info)->time_to_sleep = ft_atol(argv[4]);
	if ((*info)->num_of_philos <= 0 || (*info)->time_to_die <= 0
		|| (*info)->time_to_eat <= 0 || (*info)->time_to_sleep <= 0)
		return (er_free_info(info));
	if (argv[5] != NULL)
	{
		(*info)->must_eat = ft_atoi(argv[5]);
		if ((*info)->must_eat <= 0)
			return (er_free_info(info));
	}
	else
		(*info)->must_eat = (-1);
	(*info)->launch_time = gettime();
	return (SUCCESS);
}
