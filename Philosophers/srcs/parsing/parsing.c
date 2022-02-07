/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:39:21 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 05:27:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	parsing(t_params *params, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (-1);
	if (ft_atoi_2(*(++av), &params->n_philo) || params->n_philo < 1
		|| ft_atoi_2(*(++av), &params->t_die) || params->t_die < 1
		|| ft_atoi_2(*(++av), &params->t_eat) || params->t_eat < 0
		|| ft_atoi_2(*(++av), &params->t_sleep) || params->t_sleep < 0)
		return (-1);
	if (ac == 6)
	{
		if (ft_atoi_2(*(++av), &params->n_loop) || params->n_loop < 0)
			return (-1);
		else
			params->must_eat = true;
	}
	else
		params->must_eat = false;
	return (0);
}
