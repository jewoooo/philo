/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:52:56 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/16 10:52:29 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	one_philo_case(t_philo *philo)
{
	while (TRUE)
	{
		if (check_died_flag(philo->info) == TRUE)
			break ;
	}
}

int	philo_print(char *s, t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d %s\n", gettime() - info->launch_time,
		philo->id, s);
	pthread_mutex_unlock(&(info->print_mutex));
	return (SUCCESS);
}

int	philo_sleep(t_info *info, long sleep_time)
{
	long	start;

	start = gettime();
	while (TRUE)
	{
		if (check_died_flag(info) == TRUE || check_finished_flag(info) == TRUE)
			return (FAIL);
		if (gettime() - start >= sleep_time)
			break ;
		usleep(500);
	}
	return (SUCCESS);
}
