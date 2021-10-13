/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:48:02 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/13 12:10:12 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	show_text(t_all *all, int x, int y, int text_n)
{
	int	color;
	int	background;

	color = color_utils(all->texture[text_n], x, y);
	background = color_utils(all->texture[text_n], 0, 0);
	if (color != background)
	{
		if (x + all->x <= all->width && y + all->y <= all->height)
			my_mlx_put_pxl(&all->window.img, x + all->x, y + all->y, color);
	}
}

static int	render(t_all *all, int h, int w, int text_n)
{
	int		width;
	int		height;

	width = -1;
	all->x = w * all->size;
	all->y = h * all->size;
	while (++width < all->texture[text_n].w)
	{
		height = -1;
		while (++height < all->texture[text_n].h)
			show_text(all, width, height, text_n);
	}
	return (0);
}

static void	select_text(t_all *all, int i, int j)
{
	if (all->map[i][j] == '1')
		render(all, i, j, 0);
	else if (all->map[i][j] == 'P')
		render(all, all->player.x, all->player.y, 2);
	else if (all->map[i][j] == 'C')
		render(all, i, j, 3);
	else if (all->map[i][j] == 'E')
		render(all, i, j, 4);
	else
		render(all, i, j, 1);
}

int	first_render(t_all *all)
{
	int		j;
	int		i;

	i = -1;
	while (++i < all->n_rows)
	{
		j = -1;
		while (++j < all->n_col)
			select_text(all, i, j);
	}
	mlx_put_image_to_window(all->window.mlx_ptr, all->window.win_ptr,
		all->window.img.img, 0, 0);
	if (all->end == 1)
		close_cub(all);
	return (0);
}
