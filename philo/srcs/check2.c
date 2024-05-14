/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:11:39 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/14 16:13:47 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_created(t_info *info)
{
	pthread_mutex_lock(&(info->start_mutex));
	if (info->created == TRUE)
	{
		pthread_mutex_unlock(&(info->start_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->start_mutex));
	return (FALSE);
}
