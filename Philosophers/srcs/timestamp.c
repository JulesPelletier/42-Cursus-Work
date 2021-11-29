/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:31 by Jules             #+#    #+#             */
/*   Updated: 2021/11/29 15:47:46 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		get_chrono(void)
{
	struct timeval	chrono;
	int				i;

	i = 0;
	if (gettimeofday(&chrono, NULL) == -1)
		return (ft_exit("get time of day failed\n", 1));
	i = (chrono.tv_sec * 1000) + (chrono.tv_usec / 1000);
	return (i);
}


void	display_text(int time, t_philo philo, int i)
{
	if (i == 1)
		printf("%d ms\t | Philo %d has taken a fork\n", time, philo.number);
	else if (i == 2)
		printf("%d ms\t | Philo %d is eating\n", time, philo.number);
	else if (i == 3)
		printf("%d ms\t | Philo %d is sleeping\n", time, philo.number);
	else if (i == 4)
		printf("%d ms\t | Philo %d is thinking\n", time, philo.number);
	else if (i == 5)
		printf("%d ms\t | Philo %d died\n", time, philo.number);
	else
		printf("Error \n");
}