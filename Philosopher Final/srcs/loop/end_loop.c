/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:00:03 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 17:56:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_mutex(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->params.n_philo)
		pthread_join(all->philos[i].thread, NULL);
	pthread_mutex_destroy(&all->params.print);
	i = -1;
	while (++i < all->params.n_philo)
		pthread_mutex_destroy(&all->philos[i].left_fork);
}

void	end_loop(t_all *all)
{

	while (!check_death_all(all))
		ft_wait(1);
	close_mutex(all);
	if (all->params.end == 2)
	{
		printf(GREEN"\n ==== Game Done ==== \n\n"RESET);
		show_ate(all);
		printf("\n");
	}
	else
	{
		printf(RED"\n ==== Game Over ==== \n\n"RESET);
		show_ate(all);
		printf("\n");
	}
	free(all->philos);
}