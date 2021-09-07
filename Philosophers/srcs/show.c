/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:55:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/07 18:17:50 by Jules            ###   ########.fr       */
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
	printf("Time Init : %lld ms\n", all->time);
	printf("Count : %d\n", all->count);
	printf("Finish : %d\n", all->finish);
}

void	show_philos(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		printf("Philo %d : \n", all->philos[i].number);
		printf("Left Fork | Right Fork : %d | %d\n", all->philos[i].f_left, all->philos[i].f_right);
		printf("Is Eating : %d\n", all->philos[i].is_eating);
		printf("Count Eat : %d\n", all->philos[i].count_eat);
		printf("\n");
		i++;
	}
	printf(GREEN "PHILO INIT COMPLETE\n" RESET);
}

void	show_all(t_all *all)
{
	show_game(all);
	show_struct(all);
	show_philos(all);
}