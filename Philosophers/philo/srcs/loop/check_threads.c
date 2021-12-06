/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 03:32:58 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 06:36:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	check_condition(t_all *all, bool just_error)
{
	if (!just_error)
	{
		pthread_mutex_lock(&all->m_dead);
		if (all->death)
		{
			pthread_mutex_unlock(&all->m_dead);
			return (1);
		}
		pthread_mutex_unlock(&all->m_dead);
		pthread_mutex_lock(&all->m_a_eat);
		if (all->count_eat)
		{
			pthread_mutex_unlock(&all->m_a_eat);
			return (1);
		}
		pthread_mutex_unlock(&all->m_a_eat);
	}
	pthread_mutex_lock(&all->m_end);
	if (all->error)
	{
		pthread_mutex_unlock(&all->m_end);
		return (1);
	}
	pthread_mutex_unlock(&all->m_end);
	return (0);
}

int	check_count(t_all *all)
{
	int	i;
	int	min;

	i = -1;
	min = all->params.n_loop;
	while (++i < all->params.n_philo)
	{
		pthread_mutex_lock(&all->philo[i].m_p_eat);
		if (min > all->philo[i].count_philo)
			min = all->philo[i].count_philo;
		pthread_mutex_unlock(&all->philo[i].m_p_eat);
	}
	return (min);
}
