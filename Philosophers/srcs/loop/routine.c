/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:39:21 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 06:47:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	display(t_all *all, int i, char *str, long long int duration)
{
	long long int	now;
	long long int	elapsed;

	elapsed = 0;
	if ((str[0] == 'd' && !check_condition(all, true)) || \
		!check_condition(all, false))
	{
		if (str[3] == 'e')
		{
			pthread_mutex_lock(&all->philo[i].m_p_eat);
			all->philo[i].last_meal = get_chrono(all);
			all->philo[i].count_philo++;
			pthread_mutex_unlock(&all->philo[i].m_p_eat);
		}
		now = get_chrono(all);
		pthread_mutex_lock(&all->m_print);
		printf("%lld \t\t | Philo %d %s\n", now - all->start, \
			i + 1, str);
		pthread_mutex_unlock(&all->m_print);
		while (elapsed < duration && !check_condition(all, false))
		{
			usleep(duration * 10);
			elapsed = get_chrono(all) - now;
		}
	}
}

void	*take_fork(t_all *all, int i, bool action, int next)
{
	if (next == all->params.n_philo)
		next = 0;
	if (!action)
	{
		if (i & 1)
		{
			pthread_mutex_lock(&all->philo[i].fork);
			display(all, i, "has taken a fork", 0);
		}
		pthread_mutex_lock(&all->philo[next].fork);
		display(all, i, "has taken a fork", 0);
		if (!(i & 1))
		{
			pthread_mutex_lock(&all->philo[i].fork);
			display(all, i, "has taken a fork", 0);
		}
	}
	else
	{
		pthread_mutex_unlock(&all->philo[i].fork);
		pthread_mutex_unlock(&all->philo[next].fork);
	}
	return (NULL);
}
