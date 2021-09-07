/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:31 by Jules             #+#    #+#             */
/*   Updated: 2021/09/07 15:58:35 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
int		get_chrono(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (i);
}
*/

char	*text(int time, t_philo philo, int i)
{
	if (i == 1)
		return ("%d ms | Philo %d has taken a fork\n", time, philo.number);
	if (i == 2)
		return ("%d ms | Philo %d is eating\n", time, philo.number);
	if (i == 3)
		return ("%d ms | Philo %d is sleepinh\n", time, philo.number);
	if (i == 4)
		return ("%d ms | Philo %d is thinking\n", time, philo.number);
	if (i == 5)
		return ("%d ms | Philo %d died\n", time, philo.number);
	return ("Error \n");
}