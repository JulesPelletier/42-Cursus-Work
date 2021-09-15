/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:34:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:19:21 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	clear_images(t_all *all)
{
	if (all->args.wall.image)
		mlx_destroy_image(all->mlx.ptr, (all->args.wall.image));
	if (all->args.floor.image)
		mlx_destroy_image(all->mlx.ptr, all->args.floor.image);
	if (all->args.coin.image)
		mlx_destroy_image(all->mlx.ptr, all->args.coin.image);
	if (all->args.exit.image)
		mlx_destroy_image(all->mlx.ptr, all->args.exit.image);
	if (all->args.player.image)
		mlx_destroy_image(all->mlx.ptr, all->args.player.image);
}
