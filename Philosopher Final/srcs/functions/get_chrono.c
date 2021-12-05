/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chrono.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:59:02 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 14:59:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_chrono(void)
{
	long int		time;
	struct timeval	get_time;

	time = 0;
	if (gettimeofday(&get_time, NULL) == -1)
		return (ft_exit("get time of day function failed\n", 1));
	time = (get_time.tv_sec * 1000) + (get_time.tv_usec / 1000);
	return (time);
}