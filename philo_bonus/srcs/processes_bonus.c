/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:40:58 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/13 10:15:42 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	wait_child(t_philo *philo)
{
	int	i;
	int	cnt;
	int	status;

	cnt = 0;
	while (TRUE)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == DIED_BY_TIME
			|| WEXITSTATUS(status) == FAIL_PTH)
		{
			i = -1;
			while (++i < philo->num_of_philos)
				kill(philo->pid[i], SIGKILL);
			break ;
		}
		if (WEXITSTATUS(status) == FINISHED_MEALS)
		{
			cnt++;
			if (cnt == philo->num_of_philos)
				break ;
		}
	}
}

int	create_processes(t_philo *philo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < philo->num_of_philos)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
		{
			j = -1;
			while (++j < i)
				kill(philo->pid[j], SIGKILL);
			return (FAIL);
		}
		if (philo->pid[i] == 0)
		{
			philo->id = i + 1;
			create_thread(philo);
			child_behave(philo);
		}
	}
	wait_child(philo);
	return (SUCCESS);
}
