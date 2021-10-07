/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:25:51 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 16:49:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	init_window(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->w = 800;
	win->h = 800;
}

static void	init_image(t_img *img)
{
	img->img = NULL;
	img->adr = NULL;
	img->bits_per_pxl = 0;
	img->line_length = 0;
	img->endian = 0;
	img->w = 800;
	img->h = 800;
}

static void	init_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->up = 0;
	player->side = 0;
}

static void	init_texture(t_all *all)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		all->texture[i].ptr = NULL;
		all->texture[i].data = NULL;
		all->texture[i].name = NULL;
		all->texture[i].bits_per_pxl = 0;
		all->texture[i].line_length = 0;
		all->texture[i].endian = 0;
		all->texture[i].w = 0;
		all->texture[i].h = 0;
		i++;
	}
}

void	init_all(t_all *all)
{
	all->error = 0;
	all->map = NULL;
	all->exit = 0;
	all->start = 0;
	all->collectible = 0;
	all->n_rows = -1;
	all->n_col = -1;
	all->size = 48;
	all->width = 0;
	all->height = 0;
	all->x = 0;
	all->y= 0;
	all->fd = 0;
	all->end = 0;
	all->move = 0;
	init_window(&all->window);
	init_image(&all->img);
	init_player(&all->player);
	init_texture(all);
}
