/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:31:59 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 16:04:03 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int get_pixel(t_image *image, int x, int y)
{
    return (*(int *)(image->addr + (y * image->line_length + (x * (image->bits_per_pixel / 8)))));
}

void    set_pixel(t_image *image, int x, int y, int color)
{
    color = *(unsigned int *)(image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8)));
}

void    pixel_put(t_image *image, int x, int y, int color)
{
    char    *tmp;

    tmp = image->addr + (y * image->line_length + x*(image->bits_per_pixel / 8));
    color = *(unsigned int *)tmp;
}

void	draw_on_img(t_image *img, t_image *s_img, int startX, int startY)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < RES)
	{
		draw.y = 0;
		while (draw.y < RES)
		{
			draw.r_x = (float)draw.x / (float)RES;
			draw.r_y = (float)draw.y / (float)RES;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			if (draw.color != (int)COLOR_BLACK)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	draw_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map.map[i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (all->map.map[i][j] == '1')
				draw_on_img(&all->images, &all->wall, j * 64, i * 64);
			else
				draw_on_img(&all->images, &all->floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	draw_player(t_all *all)
{
	all->player.smooth_x += (all->player.x - all->player.smooth_x) * 0.5;
	all->player.smooth_y += (all->player.y - all->player.smooth_y) * 0.5;
	draw_on_img(&all->images, &(all->player.img_player), (int)(all->player.smooth_y * RES),
		(int)(all->player.smooth_x * RES));
}

int	render_next_frame(t_all *all)
{
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr,
		all->images.img, 0, 0);
	draw_map(all);
	//draw_elements(all);
	draw_player(all);
	all->frame++;
	return (1);
}

void    game_loop(t_all *all)
{
    mlx_loop_hook(all->mlx.mlx_ptr, render_next_frame, all);
	//mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	//mlx_hook(mem->vars->win, 33, 1L << 5, close_clean, mem);
	mlx_loop(all->mlx.mlx_ptr);
}

int draw_graphics(t_all *all)
{
    all->mlx.mlx_ptr = mlx_init();
    all->frame = 0;
    all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So_Long");
    all->images.img = mlx_new_image(all->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    all->images.addr = mlx_get_data_addr(all->images.img, &all->images.bits_per_pixel, &all->images.line_length, &all->images.endian);
    init_player_img(all);
    game_loop(all);
    return (1);
}