/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:39 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/04 19:13:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_all *all)
{
	int		i;

	i =	0;
	all->philos = (t_philo *)malloc(sizeof(t_philo) * all->params.n_philo);
	if (!all->philos)
		ft_exit("Malloc failed\n", 1);
	while (i < all->params.n_philo)
	{
		all->philos[i].number = i + 1;
		all->philos[i].count_eat = 0;
		all->philos[i].t_last_meal = all->t_start;
		all->philos[i].finish = 0;
		i++;
	}
}

t_philo	set_philo(t_all *all, t_philo philo, int i)
{
	philo.number = i + 1;
	philo.count_eat = 0;
	philo.time = all->time;
	philo.is_eating = 0;
	philo.f_left = i;
	philo.f_right = (i + 1) % all->params.n_philo;
	return (philo);
}

void	create_philos(t_all *all)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * all->params.n_philo);
	if (philos == NULL)
		return ;
	while (i < all->params.n_philo)
	{
		philos[i] = set_philo(all, philos[i], i);
		i++;
	}
	all->philos = philos;
}