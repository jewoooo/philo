/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:28:10 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/10 13:59:40 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus_h"

// ./philo_bonus 철학자수 수명 밥먹는 자는 먹어야하는횟수
int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 5 || argc > 6)
		return (FAIL);
	if (valid_argv(argc, argv) == FALSE)
		return (er_print("Invalid arguments."));
	if (init_info(&info, argv) == FAIL)
		return (er_print("Failed init_info."));
}
