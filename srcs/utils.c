/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:52:51 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 16:21:41 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
