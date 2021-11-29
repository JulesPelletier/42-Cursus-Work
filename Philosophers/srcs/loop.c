/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:34:31 by julpelle          #+#    #+#             */
/*   Updated: 2021/11/29 15:42:51 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ate(t_all *all)
{
	int	i;

	i = 0;
	//printf(MAGENTA "2nd check ate : philo %d\n" RESET, all->philos->number);
	pthread_mutex_lock(&all->n_count);
	while (i < all->params.n_philo && all->philos[i].count_eat >= all->params.n_loop && all->params.n_loop != -1)
		i++;
	pthread_mutex_unlock(&all->n_count);
	if (i == all->params.n_philo)
		return (1);
	return (0);
}

void	check_death(t_all *all)
{
	int	i;

	while (!check_ate(all))
	{
		i = -1;
		while (++i < all->params.n_philo)
		{
			//printf(MAGENTA "3rd check death : philo %d\n" RESET, all->philos[i].number);
			//printf(MAGENTA "3rd check : I : %d\n" RESET, i);
			pthread_mutex_lock(&all->eating);
			//printf(BLUE "Check : \nTime : %d \nLast meal : %d\nFirst Arg : %d\nSecond arg : %d \n" RESET, get_chrono(), all->philos[i].last_meal,get_chrono() - all->philos[i].last_meal, all->params.t_die);
			if (get_chrono() - all->philos[i].last_meal >= all->params.t_die)
			{
				//printf(MAGENTA "4th check : philo %d\n" RESET, all->philos->number);
				display_text(get_chrono() - all->start, all->philos[i], 5);
				pthread_mutex_lock(&all->died);
				all->finish = 1;
				pthread_mutex_unlock(&all->died);
			}
			pthread_mutex_unlock(&all->eating);
			usleep(100);
		}
		if (all->finish)
			break;
	}
}

void	philo_sleep(long long time, t_all *all)
{
	long long	i;

	i = get_chrono();
	while (1)
	{
		pthread_mutex_lock(&all->died);
		if (get_chrono() - i >= time || all->finish)
		{
			pthread_mutex_unlock(&all->died);
			break ;
		}
		pthread_mutex_unlock(&all->died);
		usleep(50);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->forks[philo->f_left]);
	display_text(get_chrono() - philo->all->time, *philo, 1);
	if (philo->all->params.n_philo == 1)
		return ;
	pthread_mutex_lock(&philo->all->forks[philo->f_right]);
	display_text(get_chrono() - philo->all->time, *philo, 1);
	pthread_mutex_lock(&philo->all->eating);
	display_text(get_chrono() - philo->all->time, *philo, 2);
	philo->last_meal = get_chrono();
	pthread_mutex_unlock(&philo->all->eating);
	philo_sleep(philo->all->params.t_eat, philo->all);
	pthread_mutex_lock(&philo->all->n_count);
	philo->all->count++;
	pthread_mutex_unlock(&philo->all->forks[philo->f_right]);
	pthread_mutex_unlock(&philo->all->forks[philo->f_left]);
	pthread_mutex_unlock(&philo->all->n_count);
}

void	*loop_algo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!(philo->number % 2))
		usleep((philo->all->params.t_eat * 1000) + 1000);
	while (1)
	{
		pthread_mutex_lock(&philo->all->died);
		if (philo->all->finish)
		{
			pthread_mutex_unlock(&philo->all->died);
			break ;
		}
		pthread_mutex_unlock(&philo->all->died);
		//printf("Check before\n");
		eating(philo);
		//printf("Check after\n");
		if (check_ate(philo->all) || philo->all->params.n_philo == 1)
			break ;
		display_text(get_chrono() - philo->all->time, *philo, 3);
		philo_sleep(philo->all->params.t_sleep, philo->all);
		display_text(get_chrono() - philo->all->time, *philo, 4);
		
	}
	return (0);
}

int	end_loop(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->params.n_philo)
		if (pthread_join(all->philos[i].thread, NULL))
			return (1);
	return (0);
}

int	clean_threads(t_all *all)
{
	int	i;

	if (all->philos)
		free(all->philos);
	if (all->forks)
	{
		i = -1;
		while (++i < all->params.n_philo)
			pthread_mutex_destroy(&all->forks[i]);
		free(all->forks);
	}
	pthread_mutex_destroy(&all->died);
	pthread_mutex_destroy(&all->eating);
	pthread_mutex_destroy(&all->n_count);
	return (1);
}

int	start_loop(t_all *all)
{
	int	i;

	i = -1;
	all->start = get_chrono();
	//printf("1st check\n");
	while (++i < all->params.n_philo)
	{
		if (pthread_create(&all->philos[i].thread, NULL, &loop_algo, &all->philos[i]))
			return (1);
		pthread_mutex_lock(&all->eating);
		all->philos[i].last_meal = get_chrono();
		pthread_mutex_unlock(&all->eating);
	}
	//printf("Out of loop : checking death [%d]\n", i);
	check_death(all);
	if (end_loop(all))
		return (1);
	return (0);
}