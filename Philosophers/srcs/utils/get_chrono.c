/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chrono.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 03:32:10 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 05:29:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long int	get_chrono(t_all *all)
{
	long long int	time;
	struct timeval	now;

	if (gettimeofday(&now, NULL))
	{
		pthread_mutex_lock(&all->m_end);
		all->error = true;
		pthread_mutex_unlock(&all->m_end);
		return (-1);
	}
	else
		time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (time);
}
