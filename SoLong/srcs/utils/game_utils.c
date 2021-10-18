/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:53:58 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 16:24:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	check_move(t_all *all, int x, int y)
{
	if (all->collectible > 0 && all->map[x][y] == 'E')
		return (1);
	if (all->collectible == 0 && all->map[x][y] == 'E')
		all->end = 1;
	return (0);
}

static void	show_moves(t_all *all)
{
	ft_putstr("Move :");
	ft_putnbr(all->move);
	ft_putstr("\n");
}

void	update_pos(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x - all->player.side;
	y = all->player.y + all->player.up;
	if (!check_move(all, x, y))
	{
		if (all->map[x][y] != '1' ||
			(x >= all->n_rows && x <= all->n_rows) ||
			(y >= all->n_col && y <= all->n_col))
		{
			if (all->player.up != 0 || all->player.side != 0)
			{
				if (all->map[x][y] == 'C')
					all->collectible -= 1;
				all->map[all->player.x][all->player.y] = '0';
				all->player.x = x;
				all->player.y = y;
				all->map[all->player.x][all->player.y] = 'P';
				all->move += 1;
				show_moves(all);
			}
		}
	}
}
