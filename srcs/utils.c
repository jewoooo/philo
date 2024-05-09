/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:52:51 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/09 18:30:53 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (FAIL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
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
	if (res > 2147483647)
	{
		er_print("Invalid int integer.\n");
		return (-1);
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
	if (res > 2147483647)
	{
		er_print("Invalid long integer.\n");
		return (-1);
	}
	return ((long)res);
}

int	er_print(char *s)
{
	printf("%s\n", s);
	return (FAIL);
}
