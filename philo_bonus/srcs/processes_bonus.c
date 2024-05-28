/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:40:58 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/28 16:36:46 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	handle_sigterm(int signum)
{
	exit(FAIL);
}

void	wait_child(t_philo *philo)
{
	int		i;
	int		j;
	int		status;
	pid_t	term_pid;

	i = -1;
	while (++i < philo->num_of_philos)
	{
		term_pid = waitpid(-1, &status, 0);
		if (term_pid > 0 && WIFEXITED(status) != 0
			&& WEXITSTATUS(status) != FINISHED)
		{
			j = -1;
			while (++j < philo->num_of_philos)
				kill(philo->pid[j], SIGTERM);
			printf("%ld %d died\n", gettime() - philo->launch_time,
				WEXITSTATUS(status));
			return ;
		}
	}
}

int	create_processes(t_philo *philo)
{
	int	i;
	int	j;

	philo->last_eat_time = gettime();
	i = -1;
	while (++i < philo->num_of_philos)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
		{
			j = -1;
			while (++j < i)
				kill(philo->pid[j], SIGTERM);
			return (FAIL);
		}
		if (philo->pid[i] == 0)
		{
			signal(SIGTERM, handle_sigterm);
			philo->id = i + 1;
			init_last_sem(philo);
			create_thread(philo);
			child_behave(philo);
		}
	}
	return (SUCCESS);
}
