/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:56:31 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/28 13:33:49 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	init_last_sem(t_philo *philo)
{
	philo->s_id = ft_itoa(philo->id);
	sem_unlink(philo->s_id);
	philo->last_sem = sem_open(philo->s_id, O_CREAT, 0644, 1);
	if (philo->last_sem == SEM_FAILED)
	{
		printf("philo %d: sem_open() failed.\n", philo->id);
		exit(philo->id);
	}
}

int	init_sem(t_philo **philo)
{
	sem_unlink("/forks_sem");
	(*philo)->forks_sem = sem_open("/forks_sem", O_CREAT,
			0644, (*philo)->num_of_philos);
	if ((*philo)->forks_sem == SEM_FAILED)
		return (er_unlink_free(philo));
	sem_unlink("/print_sem");
	(*philo)->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	if ((*philo)->print_sem == SEM_FAILED)
		return (er_unlink_free(philo));
	return (SUCCESS);
}

int	init_philo(t_philo **philo)
{
	int	size;

	size = (*philo)->num_of_philos;
	(*philo)->pid = malloc(sizeof(pid_t) * size);
	if ((*philo)->pid == NULL)
		return (er_unlink_free(philo));
	memset((*philo)->pid, 0, sizeof(pid_t) * size);
	return (SUCCESS);
}

int	init_info(t_philo **philo, char **argv)
{
	*philo = malloc(sizeof(t_philo));
	if (*philo == NULL)
		return (FAIL);
	memset(*philo, 0, sizeof(t_philo));
	(*philo)->num_of_philos = ft_atoi(argv[1]);
	(*philo)->time_to_die = ft_atol(argv[2]);
	(*philo)->time_to_eat = ft_atol(argv[3]);
	(*philo)->time_to_sleep = ft_atol(argv[4]);
	if ((*philo)->num_of_philos <= 0 || (*philo)->time_to_die <= 0
		|| (*philo)->time_to_eat <= 0 || (*philo)->time_to_sleep <= 0)
		return (er_free_philo(philo));
	if (argv[5] != NULL)
	{
		(*philo)->must_eat = ft_atoi(argv[5]);
		if ((*philo)->must_eat <= 0)
			return (er_free_philo(philo));
	}
	else
		(*philo)->must_eat = (-1);
	(*philo)->launch_time = gettime();
	if ((*philo)->launch_time == FAIL)
		return (er_free_philo(philo));
	return (SUCCESS);
}
