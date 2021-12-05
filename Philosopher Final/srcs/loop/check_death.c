/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:50:35 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 17:10:00 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death_philo(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->params->died);
	if (i)
		philo->params->end = i;
	if (philo->params->end)
	{
		pthread_mutex_unlock(&philo->params->died);
		return (1);
	}
	pthread_mutex_unlock(&philo->params->died);
	return (0);
}

int	check_death_all(t_all *all)
{
	pthread_mutex_lock(&all->params.died);
	if (all->params.end)
	{
		pthread_mutex_unlock(&all->params.died);
		return (1);
	}
	pthread_mutex_unlock(&all->params.died);
	return (0);
}