/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:44:26 by Jules             #+#    #+#             */
/*   Updated: 2021/09/01 10:34:34 by Jules            ###   ########.fr       */
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

void	init_philo(t_philo philo, int i)
{
	philo.number = i;
	philo.process = 0;
	philo.count_eat = 0;
	philo.f_left = i;
	philo.f_right = (i + 1) ;
	philo.is_eating = 0;
}
