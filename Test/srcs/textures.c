/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:37:28 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:56:04 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	get_textures(t_all *all)
{
	all->args.player.image = mlx_xpm_file_to_image(all->mlx.ptr,
			"./textures/nageuse.xpm",
			&(all->args.player.width), &(all->args.player.height));
	all->args.floor.image = mlx_xpm_file_to_image(all->mlx.ptr,
			"./textures/grass.xpm",
			&(all->args.floor.width), &(all->args.floor.height));
	all->args.wall.image = mlx_xpm_file_to_image(all->mlx.ptr,
			"./textures/wall.xpm",
			&(all->args.wall.width), &(all->args.wall.height));
	all->args.coin.image = mlx_xpm_file_to_image(all->mlx.ptr,
			"./textures/collectible.xpm",
			&(all->args.coin.width), &(all->args.coin.height));
	all->args.exit.image = mlx_xpm_file_to_image(all->mlx.ptr,
			"./textures/exit.xpm",
			&(all->args.exit.width), &(all->args.exit.height));
}
