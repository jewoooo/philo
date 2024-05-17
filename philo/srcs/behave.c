/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:12:24 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/17 18:28:06 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	even_behave(t_philo *philo)
{
	while (TRUE)
	{
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		sleeping(philo);
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		thinking(philo);
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		if (eating(philo) == FAIL)
			break ;
	}
}

static void	special_odd_behave(t_philo *philo)
{
	while (TRUE)
	{
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		thinking(philo);
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		if (eating(philo) == FAIL)
			break ;
		if (check_died_flag(philo->info) == TRUE
			|| check_finished_flag(philo->info) == TRUE)
			break ;
		sleeping(philo);
	}
}

void	odd_behave(t_philo *philo)
{
	if (philo->info->num_of_philos % 2 == 1
		&& philo->id == philo->info->num_of_philos)
		special_odd_behave(philo);
	else
	{
		while (TRUE)
		{
			if (check_died_flag(philo->info) == TRUE
				|| check_finished_flag(philo->info) == TRUE)
				break ;
			if (eating(philo) == FAIL)
				break ;
			if (check_died_flag(philo->info) == TRUE
				|| check_finished_flag(philo->info) == TRUE)
				break ;
			sleeping(philo);
			if (check_died_flag(philo->info) == TRUE
				|| check_finished_flag(philo->info) == TRUE)
				break ;
			thinking(philo);
		}
	}
}
