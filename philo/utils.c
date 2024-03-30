/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:05:20 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/30 18:18:02 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	atoi_for_philo(const char *s)
{
	long long	res;

	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		res += (*s - '0');
		if (res > INT_MAX)
			return (-1);
		s++;
	}
	return ((int)res);
}
