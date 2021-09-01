/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:36:14 by Jules             #+#    #+#             */
/*   Updated: 2021/08/31 16:11:41 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	show_struct(t_all *all)
{
	printf("\n===== PARAMS ====== \n");
	printf("Number of Philosophers : %d\n", all->params.n_philo);
	printf("Number of Loops : %d\n", all->params.n_loop);
	printf("Time to Die : %d\n", all->params.t_die);
	printf("Time to Eat : %d\n", all->params.t_eat);
	printf("Time to Sleep : %d\n", all->params.t_sleep);
	printf("\n");
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
		printf("Count Ate : %d\n", all->philos[i].count_eat);
		printf("\n");
		i++;
	}
}

void	parse_params(t_all *all, int ac, char **av)
{
	all->params.n_loop = ft_atoi(av[ac - 1]);
	all->params.n_philo = ft_atoi(av[1]);
	all->params.t_die = ft_atoi(av[2]);
	all->params.t_eat = ft_atoi(av[3]);
	all->params.t_sleep = ft_atoi(av[4]);	
}


void	create_philos(t_all *all)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * all->params.n_philo);
	while (i < all->params.n_philo)
	{
		init_philo(philos[i], i);
		i++;
	}
	all->philos = philos;
}
