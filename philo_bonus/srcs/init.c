/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:36:52 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/10 13:57:05 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	init_info(t_info **info, char **argv)
{
	*info = malloc(sizeof(t_info));
	if (info == NULL)
		return (FAIL);
	(*info)->num_of_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atol(argv[2]);
	(*info)->time_to_eat = ft_atol(argv[3]);
	(*info)->time_to_sleep = ft_atol(argv[4]);
	if ((*info)->num_of_philo <= 0 || (*info)->time_to_die <= 0
		|| (*info)->time_to_eat <= 0 || (*info)->time_to_sleep <= 0)
	{
		free(*info);
		return (FAIL);
	}
	if (argv[5] != NULL)
	{
		(*info)->must_eat = ft_atoi(argv[5]);
		if ((*info)->must_eat <= 0)
		{
			free(*info);
			return (FAIL);
		}
	}
	else
		(*info)->must_eat = (-1);
	return (SUCCESS);
}
