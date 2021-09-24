/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:32:28 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 17:24:13 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	load_textures(t_all *all)
{
	all->player.img_player.img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./textures/nageuse1-fond-64-left-transp.xpm", &(all->game.img_width), &(all->game.img_height));
	all->collect.img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./textures/collectibles1-64_st-transpt.xpm", &(all->game.img_width), &(all->game.img_height));
	all->floor.img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./textures/wale-64-1.xpm", &(all->game.img_width), &(all->game.img_height));
	all->exit.img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./textures/exit-fond64t-transp.xpm", &(all->game.img_width), &(all->game.img_height));
	all->wall.img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./textures/wall.xpm", &(all->game.img_width), &(all->game.img_height));
}

void	display_texture(t_all *all, void *img)
{
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, img,
		RES * all->draw.y,
		RES * all->draw.x);
}

void	ft_display(t_all *all, char c)
{
	if (c == '1')
		display_texture(all, all->wall.img);
	if (c == '0')
		display_texture(all, all->floor.img);
	if (c == 'P')
		display_texture(all, all->player.img_player.img);
	if (c == 'C')
		display_texture(all, all->collect.img);
	if (c == 'E')
		display_texture(all, all->exit.img);
}