/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:15:36 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 16:04:03 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    init_game(t_all *all)
{
    all->game.start_x = 0;
    all->game.start_y = 0;
    all->game.current_x = 0;
    all->game.current_y = 0;
    all->game.collected = 0;
    all->game.img_height = 0;
    all->game.img_width = 0;
}