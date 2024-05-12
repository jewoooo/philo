/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:07:07 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/13 01:41:21 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	philo_print(char *s, t_philo *philo)
{
	sem_wait(philo->print_sem);
	printf("%ld %d %s\n", gettime() - philo->launch_time,
		philo->id, s);
	sem_post(philo->print_sem);
}

int	check_eat_enough(t_philo *philo)
{
	sem_wait(philo->count_sem);
	if (philo->count_eating >= philo->must_eat)
	{
		sem_post(philo->count_sem);
		return (TRUE);
	}
	sem_post(philo->count_sem);
	return (FALSE);
}
