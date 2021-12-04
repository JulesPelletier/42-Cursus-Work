/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:44:26 by Jules             #+#    #+#             */
/*   Updated: 2021/12/04 20:54:49 by julpelle         ###   ########.fr       */
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

void	init_mutex(t_all *all)
{
	pthread_mutex_init(&all->text, NULL);
	pthread_mutex_init(&all->finished, NULL);
	pthread_mutex_init(&all->eating, NULL);
	pthread_mutex_init(&all->died, NULL);
}

void	init_forks(t_all *all, int i)
{
	if (all->params.n_philo == 1)
		return ;
	else if (i == all->params.n_philo - 1)
		all->philos[i].f_right = &all->philos[0].f_left;
	else
		all->philos[i].f_right = &all->philos[i + 1].f_left;

}

void	init_philos(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		all->philos[i].number = i + 1;
		all->philos[i].count_eat = 0;
		all->philos[i].t_last_meal = all->t_start;
		all->philos[i].finish = 0;
		all->philos[i].f_right = NULL;
		pthread_mutex_init(&all->philos[i].f_left, NULL);
		init_forks(all, i);
		i++;
	}
}

void	init_all(t_all *all, int ac, char **av)
{
	all->finish = 0;
	all->t_start = get_chrono();
	all->time = 0;
	all->count_eat = 0;
	init_params(all);
	parse_params(all, ac, av);
	all->philos = (t_philo *)malloc(sizeof(t_philo) * all->params.n_philo + 1);
	init_philos(all);
	init_mutex(all);
}