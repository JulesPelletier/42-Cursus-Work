/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:22:49 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:19:21 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	display_image(t_all *all, void *img)
{
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, img,
		all->args.wall.width * all->map.track_y,
		all->args.wall.height * all->map.track_x);
}

void	check_display(t_all *all, char pos)
{
	if (pos == '1')
		display_image(all, all->args.wall.image);
	if (pos == '0')
		display_image(all, all->args.floor.image);
	if (pos == 'P')
	{
		display_image(all, all->args.floor.image);
		display_image(all, all->args.player.image);
	}
	if (pos == 'C')
	{
		display_image(all, all->args.floor.image);
		display_image(all, all->args.coin.image);
	}
	if (pos == 'E')
	{
		display_image(all, all->args.floor.image);
		display_image(all, all->args.exit.image);
	}
}