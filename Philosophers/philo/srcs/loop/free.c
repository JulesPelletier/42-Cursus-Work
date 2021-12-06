/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:39:29 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 05:28:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	free_philos(t_all *all)
{
	int	i;

	i = -1;
	if (all->philo)
	{
		while (++i < all->params.n_philo)
		{
			pthread_mutex_destroy(&all->philo[i].fork);
			pthread_mutex_destroy(&all->philo[i].m_p_eat);
		}
	}
	pthread_mutex_destroy(&all->m_print);
	pthread_mutex_destroy(&all->m_dead);
	pthread_mutex_destroy(&all->m_a_eat);
	pthread_mutex_destroy(&all->m_end);
	free(all->philo);
	return (0);
}
