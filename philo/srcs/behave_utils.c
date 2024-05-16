/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:52:56 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 09:32:47 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	one_philo_case(t_philo *philo)
{
	while (TRUE)
	{
		if (check_died(philo) == TRUE)
			break ;
	}
}

void	philo_print(char *s, t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d %s\n", gettime() - info->launch_time,
		philo->id, s);
	pthread_mutex_unlock(&(info->print_mutex));
}

void	philo_sleep(long milli)
{
	long	start;

	start = gettime();
	while ((gettime() - start) < milli)
		usleep(500);
}
