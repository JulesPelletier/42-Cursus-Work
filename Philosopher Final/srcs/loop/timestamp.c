/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:57:07 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 17:25:37 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_text(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = get_chrono() - philo->params->start;
	if (time >= 0 && time <= 2147483647 && !check_death_philo(philo, 0))
	{
		printf("%ld \t\t|", time);
		printf("\tPhilo %d %s\n", philo->number, str);
	}
}