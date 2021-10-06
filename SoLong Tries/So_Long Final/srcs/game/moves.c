/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:29:19 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 15:21:16 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_pos(t_all *all)
{
	if (all->map.map[all->game.current_x][all->game.current_y] == 'P')
	{
		all->map.map[all->game.current_x][all->game.current_y] = '0';
	}
}

void	update_player(t_all *all)
{
	if (all->map.map[all->game.current_x][all->game.current_y] != 'E')
		all->map.map[all->game.current_x][all->game.current_y] = 'P';
}

void	check_exit(t_all *all)
{
	if (all->map.map[all->game.current_x][all->game.current_y] == 'E')
	{
		if (all->game.collected == all->params.count_collect)
		{
			ft_putstr_fd("\n\nWell Done!\n", 1);
			exit(1);
		}
	}
}

int	test2(t_all *all, int i, int j)
{
	if (all->map.map[i][j] == 'C')
	{
		all->game.collected++;
		return (1);
	}
	if (all->map.map[i][j] == 'E')
	{
		if (all->game.collected == all->params.count_collect)
			return (1);
		else
			return (0);
	}
	return (1);
}

void	move_up(t_all *all)
{
	if (test2(all, all->game.current_x - 1, all->game.current_y))
	{
		if (all->map.map[all->game.current_x - 1][all->game.current_y] != '1')
		{
			init_pos(all);
			all->moves++;
			all->game.current_x--;
			update_player(all);
			check_exit(all);
		}
	}
}

void	move_down(t_all *all)
{
	if (test2(all, all->game.current_x + 1, all->game.current_y))
	{
		if (all->map.map[all->game.current_x + 1][all->game.current_y] != '1')
		{
			init_pos(all);
			all->moves++;
			all->game.current_x++;
			update_player(all);
			check_exit(all);
		}
	}
}

void	move_left(t_all *all)
{
	if (test2(all, all->game.current_x, all->game.current_y - 1))
	{
		if (all->map.map[all->game.current_x][all->game.current_y - 1] != '1')
		{
			init_pos(all);
			all->moves++;
			all->game.current_y--;
			update_player(all);
			check_exit(all);
		}
	}
}

void	move_right(t_all *all)
{
	if (test2(all, all->game.current_x, all->game.current_y + 1))
	{
		if (all->map.map[all->game.current_x][all->game.current_y + 1] != '1')
		{
			init_pos(all);
			all->moves++;
			all->game.current_y++;
			update_player(all);
			check_exit(all);
		}
	}
}

void	escape(t_all *all)
{
	exit(1);
}