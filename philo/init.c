/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:52:42 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/28 23:35:08 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

int	init_info(t_info *info, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = 0;
	info->dead_flag = 0;
	return (SUCCESS);
}

int	init_philo(t_info *info)
{
	int	i;

	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philos == NULL)
		return (FAIL);
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].count_of_eating = 0;
	}
	return (SUCCESS);
}

int	init_fork(t_info *info)
{
	int	i;

	info->fork = (t_fork *)malloc(sizeof(t_fork) * info->num_of_philo);
	if (info->fork == NULL)
		return (FAIL);
	i = 0;
	while (i < info->num_of_philo)
	{
		info->fork[i].id = i + 1;
		info->fork[i].taken = 0;
		if (pthread_mutex_init(&(info->fork[i].mutex), NULL) != 0)
			return (FAIL);
		info->philos[i].r_fork = info->fork[i];
		if (i == 0)
			info->philos[i].l_fork = info->fork[info->num_of_philo - 1];
		else
			info->philos[i].l_fork = info->fork[i - 1];
	}
	return (SUCCESS);
}
