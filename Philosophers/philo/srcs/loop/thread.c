/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:39:21 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 06:50:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*loop_philo(void *ptr)
{
	t_philo		*philo;
	t_all		*all;

	philo = (t_philo *)ptr;
	all = philo->ptr;
	if (philo->number & 1)
		usleep(all->params.t_eat / 10);
	while (!check_condition(all, false))
	{
		display(all, philo->number, "is thinking", 0);
		usleep(1000);
		if (all->params.n_philo == 1)
			break ;
		if (check_condition(all, false))
			break ;
		take_fork(all, philo->number, false, philo->number + 1);
		if (check_condition(all, false))
			return (take_fork(all, philo->number, true, philo->number + 1));
		display(all, philo->number, "is eating", all->params.t_eat);
		if (check_condition(all, false))
			return (take_fork(all, philo->number, true, philo->number + 1));
		take_fork(all, philo->number, true, philo->number + 1);
		display(all, philo->number, "is sleeping", all->params.t_sleep);
	}
	return (NULL);
}

int	check_end_loop(int i, t_all *all)
{
	pthread_mutex_lock(&all->philo[i].m_p_eat);
	if ((get_chrono(all) - all->philo[i].last_meal)
		> all->params.t_die && !check_condition(all, true))
	{
		pthread_mutex_unlock(&all->philo[i].m_p_eat);
		pthread_mutex_lock(&all->m_dead);
		all->death = true;
		pthread_mutex_unlock(&all->m_dead);
		display(all, i, "died", 0);
		return (-1);
	}
	pthread_mutex_unlock(&all->philo[i].m_p_eat);
	if (all->params.must_eat && check_count(all)
		>= all->params.n_loop && !check_condition(all, true))
	{
		pthread_mutex_lock(&all->m_a_eat);
		all->count_eat = true;
		pthread_mutex_unlock(&all->m_a_eat);
		return (-1);
	}
	return (0);
}

void	loop(t_all *all, int i)
{
	all->start = get_chrono(all);
	i = -1;
	while (++i < all->params.n_philo)
		all->philo[i].last_meal = all->start;
	i = -1;
	while (++i < all->params.n_philo)
		if (!(i & 1))
			pthread_create(&all->philo[i].thread, NULL, loop_philo,
				&all->philo[i]);
	i = 0;
	while (++i < all->params.n_philo)
		if (i & 1)
			pthread_create(&all->philo[i].thread, NULL, loop_philo,
				&all->philo[i]);
	while (!check_condition(all, false))
	{
		i = -1;
		while (++i < all->params.n_philo)
			if (check_end_loop(i, all))
				break ;
	}
	i = all->params.n_philo;
	while (--i >= 0)
		pthread_join(all->philo[i].thread, NULL);
}
