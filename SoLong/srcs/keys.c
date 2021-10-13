/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:57:32 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 17:37:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	key_press(int key, t_all *all)
{
	if (key == UP)
		all->player.side = 1;
	else if (key == RIGHT)
		all->player.up = 1;
	else if (key == DOWN)
		all->player.side = -1;
	else if (key == LEFT)
		all->player.up = -1;
	else if (key == ESC)
		close_cub(all);
	update_pos(all);
	first_render(all);
	return (0);
}

int	key_release(int key, t_player *player)
{
	if (key == UP || key == DOWN)
		player->side = 0;
	else if (key == LEFT || key == RIGHT)
		player->up = 0;
	return (0);
}
