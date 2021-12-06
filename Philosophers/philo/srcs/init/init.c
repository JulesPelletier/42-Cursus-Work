/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:39:21 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 05:27:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	init_philos(int n_philo, t_all *all)
{
	int	i;

	i = -1;
	all->philo = (t_philo *)malloc(sizeof(t_philo) * n_philo);
	if (!all->philo)
		all->error = true;
	else
	{
		all->death = false;
		all->count_eat = false;
		all->error = false;
		while (++i < n_philo && !all->error)
		{
			pthread_mutex_init(&all->philo[i].fork, NULL);
			pthread_mutex_init(&all->philo[i].m_p_eat, NULL);
			all->philo[i].fork_available = true;
			all->philo[i].number = i;
			all->philo[i].count_philo = 0;
			all->philo[i].ptr = all;
		}
	}
}

void	init_mutex(t_all *all)
{
	pthread_mutex_init(&all->m_print, NULL);
	pthread_mutex_init(&all->m_dead, NULL);
	pthread_mutex_init(&all->m_a_eat, NULL);
	pthread_mutex_init(&all->m_end, NULL);
}

int	init_loop(t_all *all)
{
	all->error = false;
	all->philo = NULL;
	if (all->error)
		return (-1);
	init_mutex(all);
	init_philos(all->params.n_philo, all);
	if (all->error)
		return (-1);
	return (0);
}
