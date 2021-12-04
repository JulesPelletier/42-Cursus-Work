/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:31 by Jules             #+#    #+#             */
/*   Updated: 2021/12/04 21:07:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine(t_philo *philo)
{
	//printf("\n Debut Routine \n");
	pthread_mutex_lock(&philo->f_left);
	display_text(get_chrono() - philo->all->t_start, *philo, 1);
	if (!philo->f_right)
	{
		//printf("Check Wrong\n");
		ft_my_usleep(philo->all->params.t_die + 1);
		return ;
	}
	pthread_mutex_lock(philo->f_right);
	display_text(get_chrono() - philo->all->t_start, *philo, 1);
	display_text(get_chrono() - philo->all->t_start, *philo, 2);
	pthread_mutex_lock(&philo->all->eating);
	philo->t_last_meal = get_chrono();
	ft_my_usleep(philo->all->params.t_eat);
	pthread_mutex_unlock(&philo->all->eating);
	pthread_mutex_unlock(&philo->f_left);
	pthread_mutex_unlock(philo->f_right);
	display_text(get_chrono() - philo->all->t_start, *philo, 3);
	ft_my_usleep(philo->all->params.t_sleep);
	display_text(get_chrono() - philo->all->t_start, *philo, 4);
	//printf("\n Fin Routine \n");
}

void	*loop(void *ptr)
{
	t_philo	*philo;
	int count;

	//printf("Check 1\n");
	//printf(YELLOW"Check Loop 1\n"RESET);
	philo = (t_philo *)ptr;
	//printf(YELLOW"Philo Number : %d\n\tPhilo Count Eat : %d\n"RESET, philo->number, philo->count_eat);
	if (philo->number % 2 == 0)
		ft_my_usleep(philo->all->params.t_eat / 10);
	count = 0;
	while (!check_end(philo, 0))
	{
		pthread_create(&philo->thread_id, NULL, philo_died, ptr);
		routine(philo);
		pthread_detach(philo->thread_id);
		//show_ate(philo->all);
		//printf("Test\n\tVal 1 : %d \n\tVal 2 : %d\n", philo->count_eat + 1, philo->all->params.n_loop);
		if ((int)++philo->count_eat == philo->all->params.n_loop)
		{
			pthread_mutex_lock(&philo->all->finished);
			philo->finish = 1;
			philo->all->count_eat++;
			if (philo->all->count_eat == philo->all->params.n_philo)
			{
				pthread_mutex_unlock(&philo->all->finished);
				check_end(philo, 2);
			}
			pthread_mutex_unlock(&philo->all->finished);
			return (NULL);
		}
	}
	return (NULL);
}

int	launch_loop(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		//printf("=== : I : %d : === \n", i);
		//printf(YELLOW"Check Launch Loop\n"RESET);
		all->philos[i].all = all;
		if (pthread_create(&all->philos[i].thread, NULL, loop, &all->philos[i]) != 0)
			return (ft_exit("Pthread failed\n", 1));
		i++;
	}
	return (1);
}