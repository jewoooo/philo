/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:04:13 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/30 18:15:31 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int valid_digit(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}

int	valid_argv(char *s)
{
	if (valid_digit(s) == FALSE)
		return (FALSE);
	return (TRUE);
}
