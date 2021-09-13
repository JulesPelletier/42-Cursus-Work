/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:40:15 by Jules             #+#    #+#             */
/*   Updated: 2021/09/06 11:59:26 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	draw_square(t_all *all, t_image *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(all->mlx.img_ptr, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_env(t_all *all, int i, int j)
{
	int		k;
	if (all->map.map[j][i] == 'E')
		draw_square(all, &all->exit, i * 40, j * 40);
	if (all->map.map[j][i] == 'C')
		draw_square(all, &all->collect, i * 40, j * 40);
	if (all->map.map[j][i] == 'P')
		draw_square(all, &all->player.img_player, i * 40, j * 40);
}

void	draw_map(t_all *all)
{
	int		i;
	int		j;

	j = 0;
	while (j < all->game.img_height)
	{
		i = 0;
		while (i < all->game.img_width)
		{
			if (all->map.map[j][i] == 1)
				draw_square(all, &all->wall, i* 40, j * 40);
			else
				draw_square(all, &all->floor, i * 40, j * 40);
			draw_env(all, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_all *all)
{
	draw_map(all);
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
}