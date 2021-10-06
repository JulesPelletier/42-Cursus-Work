/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:50:14 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 11:48:29 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_params(t_all *all)
{
	all->params.collectibles = 0;
	all->params.collectibles = 0;
	all->params.fd = 0;
	all->params.height = 0;
	all->params.moves = 0;
	all->params.n_columns = 0;
	all->params.n_rows = 0;
	all->params.size = 0;
	all->params.start = 0;
	all->params.width = 0;
}

void	init_player(t_all *all)
{
	all->player.x = -1;
	all->player.y = -1;
	all->player.hor = 0;
	all->player.vert = 0;
}

void	init_image(t_all *all)
{
	all->image.img = NULL;
	all->image.adr = NULL;
	all->image.bits_per_pxl = 0;
	all->image.line_length = 0;
	all->image.endian = 0;
	all->image.w = 800;
	all->image.h = 800;
}

void	init_texture(t_texture *texture)
{
	texture->ptr = NULL;
	texture->name = NULL;
	texture->image.img = NULL;
	texture->image.adr = NULL;
	texture->image.bits_per_pxl = 0;
	texture->image.line_length = 0;
	texture->image.endian = 0;
	texture->image.w = 0;
	texture->image.h = 0;
}

void	init_all(t_all *all)
{
	all->map = NULL;
	all->end = 0;
	all->error = 0;
	all->x_pixel = 0;
	all->y_pixel = 0;
	init_params(all);
	init_image(all);
	init_player(all);
	init_texture(&all->floor);
	init_texture(&all->wall);
	init_texture(&all->user);
	init_texture(&all->collectible);
	init_texture(&all->exit);
	init_texture(&all->background);
}