/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:56:57 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 16:57:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->print);
	display_text("is sleeping", philo);
	pthread_mutex_unlock(&philo->params->print);
	ft_wait(philo->params->t_sleep);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->print);
	display_text("is thinking", philo);
	pthread_mutex_unlock(&philo->params->print);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->print);
	display_text("is eating", philo);
	pthread_mutex_unlock(&philo->params->print);
}

void	ft_take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->print);
	display_text(" has taken a fork", philo);
	pthread_mutex_unlock(&philo->params->print);
}

void	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->print);
	display_text("is dead", philo);
	pthread_mutex_unlock(&philo->params->print);
}