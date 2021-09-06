/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:36:14 by Jules             #+#    #+#             */
/*   Updated: 2021/09/03 13:34:13 by Jules            ###   ########.fr       */
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

void	parse_params(t_all *all, int ac, char **av)
{
	all->params.n_loop = ft_atoi(av[ac - 1]);
	all->params.n_philo = ft_atoi(av[1]);
	all->params.t_die = ft_atoi(av[2]);
	all->params.t_eat = ft_atoi(av[3]);
	all->params.t_sleep = ft_atoi(av[4]);	
}

t_philo	set_philo(t_all *all, t_philo philo, int i)
{
	philo.number = i + 1;
	philo.count_eat = 0;
	philo.is_eating = 0;
	philo.f_left = i;
	philo.f_right = (i + 1) % all->params.n_philo;
	if (pthread_mutex_init(&philo.t_eat, NULL))
		;
	return (philo);
}

void	create_philos(t_all *all)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * all->params.n_philo);
	if (philos == NULL)
		return ;
	while (i < all->params.n_philo)
	{
		philos[i] = set_philo(all, philos[i], i);
		i++;
	}
	all->philos = philos;
}

int	init_philo(t_all *all)
{
	int		i;

	i = -1;
	all->philos = malloc(sizeof(t_all) * all->params.n_philo);
	all->forks = malloc(sizeof(pthread_mutex_t) * all->params.n_philo);
	if (!(all->philos) || !(all->forks))
		return (2);
	while (++i < all->params.n_philo)
	{
		all->philos[i].number = i;
		all->philos[i].count_eat = 0;
		all->philos[i].f_left = i;
		all->philos[i].f_right = (i + 1) % all->params.n_philo;
		all->philos[i].is_eating = 0;
		if (pthread_mutex_init(&all->philos[i].t_eat, NULL))
			return (3);
		if (pthread_mutex_init(&all->forks[i], NULL))
			return (3);
	}
	if (pthread_mutex_init(&all->text, NULL))
		return (3);
	return (0);
}

/*
void	print_log(t_all *all)
{
	printf("%lld ms : ", all->log.timestamp);
	printf("Philo %d %s\n", all->log.philo_number, all->log.is_action);
}

int	check_philo(t_all *all)
{
	
}
*/
