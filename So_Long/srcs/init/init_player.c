/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:48:00 by Jules             #+#    #+#             */
/*   Updated: 2021/08/18 17:20:10 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    init_player(t_all *all)
{
    all->player.x = 0;
    all->player.y = 0;
    all->player.smooth_x = 0;
    all->player.smooth_y = 0;
    init_image(&all->player.img_player);
}
