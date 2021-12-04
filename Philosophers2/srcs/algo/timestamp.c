/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:31 by Jules             #+#    #+#             */
/*   Updated: 2021/12/04 19:01:47 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		get_chrono(void)
{
	struct timeval	chrono;
	long int	i;

	i = 0;
	if (gettimeofday(&chrono, NULL) == -1)
		return (ft_exit("get time of day failed\n", 1));
	i = (chrono.tv_sec * 1000) + (chrono.tv_usec / 1000);
	return (i);
}

void	ft_my_usleep(long int time)
{
	long int	i;

	i = get_chrono();
	while ((get_chrono() - i) < time)
		usleep(time / 10);
}


void	display_text(int time, t_philo philo, int i)
{
	pthread_mutex_lock(&philo.all->text);
	if (i == 1)
		printf("%d ms\t | Philo %d has taken a fork\n"RESET, time, philo.number);
	else if (i == 2)
		printf("%d ms\t | Philo %d is eating\n"RESET, time, philo.number);
	else if (i == 3)
		printf("%d ms\t | Philo %d is sleeping\n"RESET, time, philo.number);
	else if (i == 4)
		printf("%d ms\t | Philo %d is thinking\n"RESET, time, philo.number);
	else if (i == 5)
		printf("%d ms\t | Philo %d died\n"RESET, time, philo.number);
	else if (i == 6)
		printf("%d ms\t | End of game, all philos have eaten\n"RESET, time);
	else
		printf("Error \n");
	pthread_mutex_unlock(&philo.all->text);
}