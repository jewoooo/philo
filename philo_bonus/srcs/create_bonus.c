/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:40:58 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/11 23:53:19 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	create_processes(t_philo **philo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*philo)->num_of_philos)
	{
		(*philo)->pid[i] = fork();
		if ((*philo)->pid[i] == -1)
		{
			j = -1;
			while (++j < i)
				kill((*philo)->pid[j], SIGKILL);
			exit(FAIL);
		}
		if ((*philo)->pid[i] == 0)
		{
			(*philo)->id = i + 1;
			create_thread(*philo);
			child_behave(*philo);
		}
	}
	i = -1;
	while (++i < (*philo)->num_of_philos)
		wait(NULL);
}
