/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:52:51 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/09 12:15:40 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_print(char *s, t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (check_died(philo) == TRUE)
		return (FAIL);
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d %s\n", gettime() - info->launch_time
		, philo->id, s);
	pthread_mutex_unlock(&(info->print_mutex));
	return (SUCCESS);
}

int	ft_atoi(char *s)
{
	long long	res;

	if (*s < '0' || *s > '9')
		s++;
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	return ((int)res);
}

long	ft_atol(char *s)
{
	long long	res;

	while (*s < '0' || *s > '9')
		s++;
	res = 0;
    while (*s >= '0' && *s <= '9')
	{
        res = (res * 10) + (*s - '0');
        s++;
    }
    return ((long)res);
}

long	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (FAIL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
