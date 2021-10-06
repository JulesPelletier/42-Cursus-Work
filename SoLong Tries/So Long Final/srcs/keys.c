/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:41:51 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 11:54:34 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int		key_press(int key, t_all *all)
{
	if (key == W)
		all->player.vert = 1;
	else if (key == S)
		all->player.vert = -1;
	else if (key == A)
		all->player.hor = -1;
	else if (key == D)
		all->player.hor = 1;
	else if (key == ESC)
		end_game(all);
	position_update(all);
	ft_display2(all);
	return (0);
}

int		key_release(int key, t_all *all)
{
	if (key == W || key == S)
		all->player.vert = 0;
	if (key == A || key == D)
		all->player.hor = 0;
	return (0);
}