/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:30:50 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/30 18:30:32 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	init_philo(t_philo **philo, t_infos *infos)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * infos->num_of_philo);
	if (*philo == NULL)
		return (FAIL);
	i = -1;
	while (++i < infos->num_of_philo)
	{
		(*philo)[i].num = i + 1;
	}
	return (SUCCESS);
}

int	init_infos(int argc, char **argv, t_infos *infos)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (valid_argv(argv[i]) == FALSE)
			return (FAIL);
	memset(*infos, 0, sizeof(t_infos));
	infos->num_of_philo = atoi_for_philo(argv[1]);
	infos->time_to_die = atoi_for_philo(argv[2]);
	infos->time_to_eat = atoi_for_philo(argv[3]);
	infos->time_to_sleep = atoi_for_philo(argv[4]);
	if (infos->num_of_philo < 0 || infos->time_to_die < 0
		|| infos->time_to_eat < 0 || infos->time_to_sleep < 0)
		return (FAIL);
	if (argc == 6)
	{
		infos->num_of_times_must_eat = ft_atoi(argv[5]);
		if (infos->num_of_times_must_eat < 0)
			return (FAIL);
	}
	return (SUCCESS);
}
