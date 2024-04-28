/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:50:14 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/28 22:55:21 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

int	valid_argv(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] != '+' || s[i] != '-'))
			return (FALSE);
		if (s[i] == '+' || s[i] == '-')
			cnt++;
		i++;
	}
	if (cnt > 1)
		return (FALSE);
	return (TRUE);
}

int	valid_args(char **argv)
{
	if (valid_argv(argv[1]) == FALSE || ft_atoi(argv[1]) <= 0)
		return (FALSE);
	if (valid_argv(argv[2]) == FALSE || ft_atoi(argv[2]) <= 0)
		return (FALSE);
	if (valid_argv(argv[3]) == FALSE || ft_atoi(argv[3]) <= 0)
		return (FALSE);
	if (valid_argv(argv[4]) == FALSE || ft_atoi(argv[4]) <= 0)
		return (FALSE);
	if (argv[5] != NULL && valid_argv(argv[5]) == FALSE
		|| ft_atoi(argv[5]) <= 0)
		return (FALSE);
	return (TRUE);
}

