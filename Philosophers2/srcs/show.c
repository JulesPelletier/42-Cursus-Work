/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:55:05 by Jules             #+#    #+#             */
/*   Updated: 2021/12/04 16:51:32 by julpelle         ###   ########.fr       */
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
	printf("Time Init : %ld ms\n", all->t_start);
	printf("Actual Time : %ld ms \n", all->time);
	printf("Finish : %d\n", all->finish);
	printf("Count : %d\n", all->count_eat);
}

void	show_philos(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		printf(CYAN"Philo %d : \n"RESET, all->philos[i].number);
		printf("Count Eat : %d\n", all->philos[i].count_eat);
		printf("Last Meal : %ld\n", all->philos[i].t_last_meal);
		printf("\n");
		i++;
	}
	printf(GREEN "PHILO INIT COMPLETE\n" RESET);
}

void	show_philos2(t_philo *philos)
{
	printf(RED"Check\n"RESET);
	printf("Philo %d : \n", philos->number);
	printf(RED"Check\n"RESET);
	printf("Count Eat : %d\n", philos->count_eat);
	printf("Last Meal : %ld\n", philos->t_last_meal);
	printf("\n");
	printf(MAGENTA "PHILO INIT COMPLETE\n" RESET);
}

void	show_ate(t_all *all)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < all->params.n_philo)
	{
		printf("Philo %d has eaten %d times \n", all->philos[i].number, all->philos[i].count_eat);
		i++;
	}
	printf("\n");
}

void	show_all(t_all *all)
{
	show_game(all);
	show_struct(all);
	show_philos(all);
}