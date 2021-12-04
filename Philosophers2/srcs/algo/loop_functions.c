/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:34:31 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/04 20:58:12 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_died(void *ptr)
{
	t_philo	*philo;

	//printf(YELLOW"Check Philo Died\n"RESET);
	philo = (t_philo *)ptr;
	ft_my_usleep(philo->all->params.t_eat);
	pthread_mutex_lock(&philo->all->eating);
	pthread_mutex_lock(&philo->all->finished);
	if (!check_end(philo, 0) && !philo->finish && (get_chrono() - philo->t_last_meal >= (long)philo->all->params.t_die))
	{
		pthread_mutex_unlock(&philo->all->eating);
		pthread_mutex_unlock(&philo->all->finished);
		pthread_mutex_lock(&philo->all->text);
		display_text(get_chrono(), *philo, 5);
		pthread_mutex_unlock(&philo->all->text);
		check_end(philo, 1);
	}
	//printf(YELLOW"Check Philo Died End\n"RESET);
	pthread_mutex_unlock(&philo->all->eating);
	pthread_mutex_unlock(&philo->all->finished);
	return (NULL);
}