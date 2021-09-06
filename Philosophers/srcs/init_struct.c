/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:44:26 by Jules             #+#    #+#             */
/*   Updated: 2021/09/03 13:28:17 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_params(t_all *all)
{
	all->params.n_loop = 0;
	all->params.n_philo = 0;
	all->params.t_die = 0;
	all->params.t_eat = 0;
	all->params.t_sleep = 0;
}

void	init_log(t_all *all)
{
	all->log.philo_number = 0;
	all->log.timestamp = 0;
	all->log.is_action = NULL;
}

void	init_all(t_all *all)
{
	all->finish = 0;
	all->count = 0;
	init_params(all);
	init_log(all);
}
