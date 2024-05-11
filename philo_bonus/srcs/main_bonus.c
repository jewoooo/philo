/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:47:21 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/11 22:56:08 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

// ./philo 철학자수 수명 식사시간 수면시간 [먹어야하는횟수]
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
	return (SUCCESS);
}
