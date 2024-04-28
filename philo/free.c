/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:56:28 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/29 00:57:36 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

int	free_all(t_info *info)
{
	if (info->philos != NULL)
		free(info->philos);
	if (info->fork != NULL)
		free(info->fork);
	if (info->NULL)
		free(info);
	return (SUCCESS);
}
