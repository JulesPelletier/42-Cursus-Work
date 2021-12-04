/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:43:10 by Jules             #+#    #+#             */
/*   Updated: 2021/12/04 21:06:17 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end2(t_all *all)
{
	pthread_mutex_lock(&all->died);
	if (all->finish)
	{
		pthread_mutex_unlock(&all->died);
		return (1);
	}
	pthread_mutex_unlock(&all->died);
	return (0);
}

void	end_loop(t_all *all)
{
	int	i;

	i = -1;
	while (!check_end2(all))
		ft_my_usleep(1);
	while (++i < all->params.n_philo)
		pthread_join(all->philos[i].thread, NULL);
	pthread_mutex_destroy(&all->text);
	i = -1;
	while (++i < all->params.n_philo)
		pthread_mutex_destroy(&all->philos[i].f_left);
	if (all->finish == 2)
		printf(GREEN"Game Done\n"RESET);
	show_ate(all);
	free(all->philos);
}

int	main(int ac, char **av)
{
	t_all	all;

	memset(&all, 0, sizeof(t_all));
	if (check_params(ac, av) < 0)
		return (0);
	init_all(&all, ac, av);
	//show_all(&all);
	/*
	if (start_loop(&all))
		return (clean_threads(&all));
	*/
	if (!launch_loop(&all))
		return (0);
	end_loop(&all);
	return (0);
}