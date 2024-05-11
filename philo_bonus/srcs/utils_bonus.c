/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:49:12 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/11 22:27:38 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

long	ft_atol(char *s)
{
	long long	res;

	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		if (res > 2147483647)
		{
			er_print("Invalid long integer.");
			return (-1);
		}
		s++;
	}
	return ((long)res);
}

int	ft_atoi(char *s)
{
	long long	res;

	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		if (res > 2147483647)
		{
			er_print("Invalid integer.");
			return (-1);
		}
		s++;
	}
	return ((int)res);
}

long	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (FAIL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}