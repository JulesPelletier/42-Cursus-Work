/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:11:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/07 18:17:18 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(&all->forks[philo->f_left]);
	pthread_mutex_lock(&all->forks[philo->f_right]);
}

void	no_fork(t_all *all, t_philo *philo)
{
	pthread_mutex_unlock(&all->forks[philo->f_left]);
	pthread_mutex_unlock(&all->forks[philo->f_right]);
}

void	is_eating(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	usleep(all->params.t_eat * 1000);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->eat);
}

void	is_sleeping(t_all *all, t_philo *philo)
{
	usleep(all->params.t_sleep * 1000);
}