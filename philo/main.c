/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:54:42 by jewlee            #+#    #+#             */
/*   Updated: 2024/04/28 23:29:26 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 철학자의 수, 철학자의 수명, 밥 먹는데 걸리는 시간, 잠자는 시간, 최소 횟수
// 4 or 5
#include "./philosopher.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (FAIL);
	if (valid_args(argv) == FALSE)
		return (FAIL);
	if (init_info(&info, argv) == FAIL)
		return (FAIL);
	if (init_philo(&info) == FAIL)
		return (FAIL);
	if (init_fork(&info) == FAIL)
		return (FAIL);
	if (solve(&info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
