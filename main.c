/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:40 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/30 18:25:10 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)
{
	t_infos	infos;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (FAIL);
	if (init_infos(argc, argv, &infos) == FAIL)
		return (FAIL);
	if (init_philo(&philo, infos) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
