/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:43:13 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 16:59:16 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	game_start(t_all *all)
{
	calculate_h_and_w(all);
	find_player(all);
	all->game.current_x = all->player.x;
	all->game.current_y = all->player.y;
	show_struct(all);
}

