/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:38:14 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/04 14:51:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	
}

void	*thread_loop(void *ptr)
{
	t_philo	*philo;
	philo = (t_philo *)ptr;
	if (philo->number % 2 == 0)
		ft_sleep();
	while (check_death())
	{
		pthread_create(&philo->thread_id, NULL, ft_isdead, ptr);
		pthread_detach(philo->thread_id);
		
	}
}

int	loop_algo(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		if (pthread_create(&all->philos->thread_id, NULL, thread_loop, &all->philos[i]) != 0)
			return (ft_exit("thread creation failed\n", 1));
		i++;
	}
	return (1);
}