/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:47:21 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/05 11:49:43 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (er_print("Usage: ./program a b c d [e]"));
	if (valid_argv(argc, argv) == FAIL)
		return (er_print("Invalid arguments."));
	if (init_info(&philo, argv) == FAIL)
		return (er_print("Failed init_info."));
	if (init_sem(&philo) == FAIL)
		return (er_print("Failed init_sem."));
	if (init_philo(&philo) == FAIL)
		return (er_print("Failed init_philo."));
	if (create_processes(philo) == FAIL)
		return (er_print("Failed create_proccess"));
	wait_child(philo);
	unlink_free(&philo);
	exit(SUCCESS);
}
