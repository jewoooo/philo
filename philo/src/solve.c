/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:27:40 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/29 09:25:15 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&(info))
}

int	solve(t_info *info)
{
	int	i;

	info->died = FALSE;
	i = -1;
	while (++i < info->num_of_philo)
		if (pthread_create(&(info->philos[i].th), NULL, routine, &(info->philos[i])) != 0)
			return (FAIL);
	i = -1;
	while (++i < info->num_of_philo)
		if ((pthread_join(info->philos[i].th), NULL) != 0)
			return (FAIL);
	return (SUCCESS);
}
