/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:13:31 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 17:34:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_died(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_wait(philo->params->t_die + 1);
	pthread_mutex_lock(&philo->params->eating);
	if (!check_death_philo(philo, 0) && !philo->finish && ((get_chrono() - philo->t_last_meal) \
		>= (long)(philo->params->t_die)))
	{
		pthread_mutex_unlock(&philo->params->eating);
		ft_is_dead(philo);
		check_death_philo(philo, 1);
	}
	pthread_mutex_unlock(&philo->params->eating);
	return (NULL);
}

void	*threads(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->number % 2 == 0)
		ft_wait(philo->params->t_eat / 10);
	while (!check_death_philo(philo, 0))
	{
		pthread_create(&philo->thread_dead, NULL, philo_died, ptr);
		routine(philo);
		pthread_detach(philo->thread_dead);
		if ((int)philo->count_eat == philo->params->n_loop)
		{
			pthread_mutex_lock(&philo->params->finished);
			philo->finish = 1;
			philo->params->count_philos++;
			if (philo->params->count_philos == philo->params->n_philo)
			{
				pthread_mutex_unlock(&philo->params->finished);
				check_death_philo(philo, 2);
			}
			pthread_mutex_unlock(&philo->params->finished);
			return (NULL);
		}
	}
	return (NULL);
}

int	loop(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->params.n_philo)
	{
		all->philos[i].params = &all->params;
		if (pthread_create(&all->philos[i].thread, NULL, threads, &all->philos[i]) != 0)
			return (ft_exit("Thread creation failed\n", 1));
		i++;
	}
	return (1);
}
