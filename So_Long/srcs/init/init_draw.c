/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:25 by Jules             #+#    #+#             */
/*   Updated: 2021/08/17 14:52:36 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    init_draw(t_all *all)
{
    all->draw.x = 0;
    all->draw.y = 0;
    all->draw.r_x = 0;
    all->draw.r_y = 0;
    all->draw.color = 0;
    all->draw.pos_x = 0;
    all->draw.pos_y = 0;
    all->draw.p_data_x = 0;
    all->draw.p_data_y = 0;
}