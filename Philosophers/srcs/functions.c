/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:36:14 by Jules             #+#    #+#             */
/*   Updated: 2021/11/29 14:59:12 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_params(t_all *all, int ac, char **av)
{
	all->params.n_philo = ft_atoi(av[1]);
	all->params.t_die = ft_atoi(av[2]);
	all->params.t_eat = ft_atoi(av[3]);
	all->params.t_sleep = ft_atoi(av[4]);
	if (av[5])
		all->params.n_loop = ft_atoi(av[ac - 1]);
	else
		all->params.n_loop = -1;
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