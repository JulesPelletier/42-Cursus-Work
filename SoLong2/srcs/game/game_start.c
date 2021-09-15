/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:43:13 by Jules             #+#    #+#             */
/*   Updated: 2021/09/10 14:07:06 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    calculate_h_and_w(t_all *all)
{
    all->game.img_height = WIN_HEIGHT / all->params.len_x;
    all->game.img_width = WIN_WIDTH / all->params.len_y;
}

void	game_start(t_all *all)
{
	calculate_h_and_w(all);
	find_player(all);
	all->game.current_x = all->player.x;
	all->game.current_y = all->player.y;
	show_struct(all);
}