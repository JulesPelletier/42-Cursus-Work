/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:12:54 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 16:49:29 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parse(int ac, char **av, t_params *params)
{
	int		i;

	if (check_params(ac, av))
		return (0);
	i = 1;
	params->n_philo = ft_atoi(av[1]);
	params->t_die = ft_atoi(av[2]);
	params->t_eat = ft_atoi(av[3]);
	params->t_sleep = ft_atoi(av[4]);
	params->n_loop = -1;
	if (ac == 6)
		params->n_loop = ft_atoi(av[5]);
	if (params->n_philo <= 0 || params->t_die <= 0 \
			|| params->t_eat <= 0 || params->t_sleep <= 0)
		return (0);
	return (1);
}

void	init_mutex(t_all *all)
{
	pthread_mutex_init(&all->params.eating, NULL);
	pthread_mutex_init(&all->params.died, NULL);
	pthread_mutex_init(&all->params.print, NULL);
	pthread_mutex_init(&all->params.finished, NULL);
}

int	init_loop(t_all *all)
{
	int	i;

	i = 0;
	all->params.start = get_chrono();
	all->params.end = 0;
	all->params.count_philos = 0;
	init_mutex(all);
	while (i < all->params.n_philo)
	{
		all->philos[i].number = i + 1;
		all->philos[i].t_last_meal = all->params.start;
		all->philos[i].count_eat = 0;
		all->philos[i].finish = 0;
		all->philos[i].right_fork = NULL;
		pthread_mutex_init(&all->philos[i].left_fork, NULL);
		if (all->params.n_philo == 1)
			return (1);
		if (i == all->params.n_philo - 1)
			all->philos[i].right_fork = &all->philos[0].left_fork;
		else
			all->philos[i].right_fork = &all->philos[i + 1].left_fork;
		i++;
	}
	return (1);
}
