/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:21:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/28 13:23:06 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*put_int(char *ptr, long long num)
{
	int			i;
	long long	div;

	i = 0;
	if (num < 0)
	{
		ptr[i++] = '-';
		num *= (-1);
	}
	div = 1;
	while (num / div)
		div *= 10;
	div /= 10;
	while (1)
	{
		ptr[i++] = (num / div) + '0';
		num %= div;
		div /= 10;
		if (div == 0)
			break ;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_itoa(long n)
{
	char			*n_str;
	int				i;
	long long		num;

	n_str = (char *)malloc(sizeof(char) * (int_len(n) + 1));
	if (n_str == 0)
		return (0);
	i = 0;
	num = (long long)n;
	if (num == 0)
	{
		n_str[i] = '0';
		n_str[i + 1] = '\0';
		return (n_str);
	}
	n_str = put_int(n_str, num);
	return (n_str);
}
