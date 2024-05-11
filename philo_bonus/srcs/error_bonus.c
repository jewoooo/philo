/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:27:26 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/11 23:47:55 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	er_unlink_free(t_philo **philo)
{
	if ((*philo)->forks_sem == SEM_FAILED)
		sem_unlink((*philo)->forks_sem);
	if ((*philo)->print_sem == SEM_FAILED)
		sem_unlink((*philo)->print_sem);
	if ((*philo)->count_sem == SEM_FAILED)
		sem_unlink((*philo)->count_sem);
	if ((*philo)->last_sem == SEM_FAILED)
		sem_unlink((*philo)->last_sem);
	return (er_free_philo(philo));
}

int	er_free_philo(t_philo **philo)
{
	free(*philo);
	return (FAIL);
}

int	er_print(char *s)
{
	printf("%s\n", s);
	return (FAIL);
}