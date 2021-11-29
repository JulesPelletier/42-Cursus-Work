/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:44:26 by Jules             #+#    #+#             */
/*   Updated: 2021/11/29 15:24:19 by julpelle         ###   ########.fr       */
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

void	init_philo(t_all *all)
{
	int		i;

	i =	0;
	all->philos = (t_philo *)malloc(sizeof(t_philo) * all->params.n_philo);
	if (!all->philos)
		ft_exit("Malloc failed\n", 1);
	while (i < all->params.n_philo)
	{
		all->philos[i].time = get_chrono() - all->time;
		all->philos[i].number = i + 1;
		all->philos[i].count_eat = 0;
		all->philos[i].f_left = i;
		all->philos[i].f_right = (i + 1) % all->params.n_philo;
		all->philos[i].is_eating = 0;
		all->philos[i].all = all;
		i++;
	}
}

int	init_mutex(t_all *all)
{
	int	i;

	all->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *
		all->params.n_philo);
	if (!all->forks)
		return (ft_exit("Malloc failed\n", 1));
	i = -1;
	while (++i < all->params.n_philo)
		if (pthread_mutex_init(&all->forks[i], NULL))
			return (ft_exit("Malloc failed\n", 1));
	if (pthread_mutex_init(&all->n_count, NULL))
		return (ft_exit("Malloc failed\n", 1));
	if (pthread_mutex_init(&all->eating, NULL))
		return (ft_exit("Malloc failed\n", 1));
	if (pthread_mutex_init(&all->died, NULL))
		return (ft_exit("Malloc failed\n", 1));
	return (0);
}

void	init_all(t_all *all, int ac, char **av)
{
	all->finish = 0;
	all->start = get_chrono();
	all->time = all->start;
	all->count = 0;
	init_params(all);
	parse_params(all, ac, av);
	init_philo(all);
	init_mutex(all);
}