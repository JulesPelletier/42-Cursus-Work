/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:27:35 by Jules             #+#    #+#             */
/*   Updated: 2021/09/20 16:48:40 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	display_texture(t_all *all, int x, int y, t_texture *text)
{
	int	color;
	int	background;

	color = get_color(text, x, y);
	background = get_color(&all->background, x, y);
	if (color != background)
	if (1)
	{
		if (x + all->x_pixel < all->params.width
			&& y + all->y_pixel < all->params.height)
			my_mlx_put_pxl(&all->mlx.img, x + all->x_pixel, y + all->y_pixel, color);
	}
}

int	ft_display(t_all *all, int h, int w, t_texture *text)
{
	int	width;
	int	height;

	width = -1;
	all->x_pixel = w * all->params.size;
	all->y_pixel = h * all->params.size;
	while (++width < text->image.w)
	{
		height = -1;
		while (++height < text->image.h)
			display_texture(all, width, height, text);
	}
	return (0);
}

void	texture_menu(t_all *all, int i, int j)
{
	if (all->map[i][j] == '1')
		ft_display(all, i, j, &all->wall);
	else if (all->map[i][j] == '0')
		ft_display(all, i, j, &all->floor);
	else if (all->map[i][j] == 'C')
		ft_display(all, i, j, &all->collectible);
	else if (all->map[i][j] == 'E')
		ft_display(all, i, j, &all->exit);
	else
		ft_display(all, i, j, &all->user);
}

int	ft_display2(t_all *all)
{
	int		j;
	int		i;
	char	*move;

	i = -1;
	while (++i < all->params.n_rows)
	{
		j = -1;
		while (++j < all->params.n_columns)
			texture_menu(all, i, j);
	}
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr,
		all->mlx.img.img, 0, 0);
	move = ft_itoa(all->params.moves);
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr, 20, 40,
		0xFF000000, move);
	free(move);
	if (all->end == 1)
	{
		ft_putstr_fd("Well Done !\n", 1);
		end_game(all);
	}
	return (0);
}