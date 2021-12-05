/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:12:50 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 15:45:55 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_wait(long int time)
{
	long int	start_time;

	start_time = 0;
	start_time = get_chrono();
	while ((get_chrono() - start_time) < time)
		usleep(time / 10);
}