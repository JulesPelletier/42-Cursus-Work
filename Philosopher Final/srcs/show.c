/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:55:05 by Jules             #+#    #+#             */
/*   Updated: 2021/12/05 15:19:50 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	show_struct(t_all *all)
{
	printf("\n===== PARAMS ====== \n");
	printf("Number of Philosophers : %d\n", all->params.n_philo);
	printf("Number of Loops : %d\n", all->params.n_loop);
	printf("Time to Die : %d ms\n", all->params.t_die);
	printf("Time to Eat : %d ms\n", all->params.t_eat);
	printf("Time to Sleep : %d ms\n", all->params.t_sleep);
	printf("\n");
}

void	show_game(t_all *all)
{
	printf("\n===== GAME ====== \n");
	printf("Time Init : %ld ms\n", all->params.start);
	printf("Finish : %d\n", all->params.end);
	printf("Count : %d\n", all->params.count_philos);
}

void	show_philos(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		printf("Philo %d : \n", all->philos[i].number);
		printf("Count Eat : %d\n", all->philos[i].count_eat);
		printf("\n");
		i++;
	}
	printf(GREEN "PHILO INIT COMPLETE\n" RESET);
}

void	show_ate(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		printf("Philo %d has eaten %d times \n", all->philos[i].number, all->philos[i].count_eat);
		i++;
	}
}

void	show_all(t_all *all)
{
	show_game(all);
	show_struct(all);
	show_philos(all);
}