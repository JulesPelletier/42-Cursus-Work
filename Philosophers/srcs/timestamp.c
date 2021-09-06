/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:31 by Jules             #+#    #+#             */
/*   Updated: 2021/09/01 13:44:30 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_chrono(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (i);
}