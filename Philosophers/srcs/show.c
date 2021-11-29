/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:55:05 by Jules             #+#    #+#             */
/*   Updated: 2021/11/25 17:24:52 by julpelle         ###   ########.fr       */
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
	printf("Actual Time : %lld ms \n", all->time);
	printf("Finish : %d\n", all->finish);
	printf("Count : %d\n", all->count);
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
		printf("Time : %d\n", all->philos[i].time);
		printf("\n");
		i++;
	}
	printf(GREEN "PHILO INIT COMPLETE\n" RESET);
}

void	show_philos2(t_philo *philos)
{
	printf(RED"Check\n"RESET);
	printf("Philo %d : \n", philos->number);
	printf("Left Fork | Right Fork : %d | %d\n", philos->f_left,philos->f_right);
	printf("Is Eating : %d\n", philos->is_eating);
	printf(RED"Check\n"RESET);
	printf("Count Eat : %d\n", philos->count_eat);
	printf("Time : %d\n", philos->time);
	printf("\n");
	printf(MAGENTA "PHILO INIT COMPLETE\n" RESET);
}

void	show_all(t_all *all)
{
	show_game(all);
	show_struct(all);
	show_philos(all);
}