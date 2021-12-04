/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:38:14 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/04 21:04:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_philo *philo, int i)
{
	//printf(YELLOW"Check End\n"RESET);
	pthread_mutex_lock(&philo->all->died);
	if (i)
		philo->all->finish = i;
	if (philo->all->finish == 1)
	{
		pthread_mutex_unlock(&philo->all->died);
		return (1);
	}
	pthread_mutex_unlock(&philo->all->died);
	return (0);
}