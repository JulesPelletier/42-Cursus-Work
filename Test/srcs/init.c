/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:02:56 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:24:20 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_image(t_img *img)
{
	img->image = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->color = 0;
	img->endian = 0;
	img->size_line = 0;
	img->width = 0;
	img->height = 0;
}

void	init_all(t_all *all)
{
	init_image(&(all->args.player));
	init_image(&(all->args.coin));
	init_image(&(all->args.exit));
	init_image(&(all->args.wall));
	init_image(&(all->args.floor));
	all->mlx.ptr = NULL;
	all->mlx.win = NULL;
	all->args.matrix = NULL;
	all->args.map = NULL;
	all->moves = 0;
}