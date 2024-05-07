/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:39:33 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/07 15:23:25 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// ./philo 철학자수 수명 밥먹는시간 잠자는시간 [최소밥횟수]
int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (FAIL);
	if (valid_argv(argc, argv) == FALSE)
		return (FAIL);
	if (init_info(&info, argv) == FAIL)
		return (FAIL);
	if (init_philos(&info, &philos) == FAIL)
		return (FAIL);
	if (init_fork(&info, philos) == FAIL)
		return (FAIL);
	if (init_mutex(&info, philos) == FAIL)
		return (FAIL);
	if (create_thread(&info, philos) == FAIL)
		return (FAIL);
	destroy_mutex(&info, philos);
	free_all(&philos, &(info.forks));
	return (SUCCESS);
}
