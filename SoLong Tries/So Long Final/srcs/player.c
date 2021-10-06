/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:08:16 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:24:16 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_move(t_all *all, int x, int y)
{
	if (all->params.collectibles > 0 && all->map[x][y] == 'E')
		return (1);
	if (all->params.collectibles == 0 && all->map[x][y] == 'E')
		all->end = 1;
	return (0);
}

void	print_moves(t_all *all)
{
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(all->params.moves, 1);
	ft_putstr_fd("\n", 1);
}

void	position_update(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x - all->player.vert;
	y = all->player.y + all->player.hor;
	if (!check_move(all, x, y))
	{
		if (all->map[x][y] != '1' ||
			(x >= all->params.n_rows && x <= all->params.n_rows) ||
			(y >= all->params.n_columns && y <= all->params.n_columns))
		{
			if (all->player.hor != 0 || all->player.vert != 0)
			{
				if (all->map[y][y] == 'C')
					all->params.collectibles -= 1;
				all->map[all->player.x][all->player.y] = '0';
				all->player.x = x;
				all->player.y = y;
				all->map[all->player.x][all->player.y] = 'P';
				all->params.moves += 1;
				print_moves(all);
			}
		}
	}
}