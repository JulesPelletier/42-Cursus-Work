/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:34:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:28:33 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	key_press(int keycode, t_all *all)
{
	all->gps.event = 1;
	if (keycode == UP)
		all->gps.move.y = -1;
	else if (keycode == DOWN)
		all->gps.move.y = 1;
	else if (keycode == LEFT)
		all->gps.move.x = -1;
	else if (keycode == RIGHT)
		all->gps.move.x = 1;
	else if (keycode == ESC)
		ft_clean(all);
	all->gps.event = 1;
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	all->gps.event = 0;
	all->gps.move.x = 0;
	all->gps.move.y = 0;
	(void)keycode;
	return (0);
}