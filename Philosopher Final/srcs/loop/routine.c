/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:47:02 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 17:34:49 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_take_a_fork(philo);
	if (!philo->right_fork)
	{
		ft_wait(philo->params->t_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	ft_take_a_fork(philo);
	ft_eating(philo);
	philo->count_eat++;
	philo->t_last_meal = get_chrono();
	pthread_mutex_unlock(&philo->params->eating);
	pthread_mutex_unlock(&philo->params->print);
	ft_wait(philo->params->t_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	ft_sleep(philo);
	ft_think(philo);
}
