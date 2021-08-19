/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:29:19 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 17:07:54 by Jules            ###   ########.fr       */
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
		ft_putstr_fd("\n\nWell Done!\n", 1);
		exit(1);
	}
}

void	move_up(t_all *all)
{
	if (all->map.map[all->game.current_x - 1][all->game.current_y] != '1')
	{
		init_pos(all);
		all->moves++;
		all->game.current_x--;
		update_player(all);
		check_exit(all);
	}
	show_map(all);
	show_game(all);
}

void	move_down(t_all *all)
{
	if (all->map.map[all->game.current_x + 1][all->game.current_y] != '1')
	{
		init_pos(all);
		all->moves++;
		all->game.current_x++;
		update_player(all);
		check_exit(all);
	}
	show_map(all);
	show_game(all);

}

void	move_left(t_all *all)
{
	if (all->map.map[all->game.current_x][all->game.current_y - 1] != '1')
	{
		init_pos(all);
		all->moves++;
		all->game.current_y--;
		update_player(all);
		check_exit(all);
	}
	show_map(all);
	show_game(all);

}

void	move_right(t_all *all)
{
	if (all->map.map[all->game.current_x][all->game.current_y + 1] != '1')
	{
		init_pos(all);
		all->moves++;
		all->game.current_y++;
		update_player(all);
		check_exit(all);
	}
	show_map(all);
	show_game(all);
}

void	escape(t_all *all)
{
	exit(1);
}