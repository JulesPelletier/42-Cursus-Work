/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:34:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:34:07 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	redraw_pos(t_all *all, t_coor old_pos, int id)
{
	all->moves++;
	printf("Number of moves: %d\n", all->moves);
	if (id == 1)
		all->gps.pos.y -= 1;
	if (id == 2)
		all->gps.pos.y += 1;
	if (id == 3)
		all->gps.pos.x -= 1;
	if (id == 4)
		all->gps.pos.x += 1;
	all->args.matrix[(int)all->gps.pos.y]
	[(int)all->gps.pos.x] = 'P';
	all->args.matrix[(int)old_pos.y][(int)old_pos.x] = '0';
}

void	redefine_pos(t_all *all)
{
	t_coor	old_pos;
	char	*block;

	if (all->collectibles != 0)
		block = ft_strdup("1E");
	else
		block = ft_strdup("1");
	old_pos.y = all->gps.pos.y;
	old_pos.x = all->gps.pos.x;
	if (all->gps.move.y == -1 && check_charset(all->args.matrix[(int)
				(all->gps.pos.y - 1)][(int)all->gps.pos.x], block) == -1)
		redraw_pos(all, old_pos, 1);
	else if (all->gps.move.y == 1 && check_charset(all->args.matrix[(int)
				(all->gps.pos.y + 1)][(int)all->gps.pos.x], block) == -1)
		redraw_pos(all, old_pos, 2);
	else if (all->gps.move.x == -1 && check_charset(all->args.matrix[(int)
				all->gps.pos.y][(int)(all->gps.pos.x - 1)], block) == -1)
		redraw_pos(all, old_pos, 3);
	else if (all->gps.move.x == +1 && check_charset(all->args.matrix[(int)
				all->gps.pos.y][(int)(all->gps.pos.x + 1)], block) == -1)
		redraw_pos(all, old_pos, 4);
	free(block);
}

void	draw_map(t_all *all)
{
	char	pos;

	all->map.track_x = 0;
	while (all->args.matrix[all->map.track_x])
	{
		all->map.track_y = 0;
		while (all->args.matrix[all->map.track_x][all->map.track_y])
		{
			pos = all->args.matrix[all->map.track_x][all->map.track_y];
			check_display(all, pos);
			all->map.track_y++;
		}
		all->map.track_x++;
	}
}

void	draw(t_all *all)
{
	all->map.track_x = 0;
	while (all->args.matrix[all->map.track_x])
	{
		all->map.track_y = 0;
		while (all->args.matrix[all->map.track_x][all->map.track_y])
		{
			mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
				all->args.floor.image,
				all->map.track_y * 64, all->map.track_x * 64);
			all->map.track_y++;
		}
		all->map.track_x++;
	}
}

int	new_map(t_all *all)
{
	redefine_pos(all);
	draw_map(all);
	return (0);
}