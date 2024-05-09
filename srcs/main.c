/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:39:33 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/09 14:58:51 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (FAIL);
	if (valid_argv(argc, argv) == FALSE)
		return (er_print("Invalid arguments.\n"));
	if (init_info(&info, argv) == FAIL)
		return (er_print("Failed init_info.\n"));
	if (init_philos(&info, &philos) == FAIL)
		return (er_print("Failed init_philos.\n"));
	if (init_forks(&info, &philos) == FAIL)
		return (er_print("Failed init_forks.\n"));
	if (init_mutex(&info, &philos) == FAIL)
		return (er_print("Failed init_mutex.\n"));
	if (create_thread(&info, &philos) == FAIL)
		return (er_print("Failed create_thread.\n"));
	if (join_thread(&info, &philos) == FAIL)
		return (er_print("Failed join_thread.\n"));
	destroy_mutex(info, philos);
	free_all(&info, &philos, &(info->forks));
	return (SUCCESS);
}
