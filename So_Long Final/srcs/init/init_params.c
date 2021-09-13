/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:55:29 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 16:04:03 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void init_params(t_all *all)
{
    all->params.len_x = 0;
    all->params.len_y = 0;
    all->params.count_exit = 0;
    all->params.count_starting_pos = 0;
    all->params.count_collect = 0;
    all->params.flag_map_closed = 0;
    all->params.flag_extension = 0;
    all->params.flag_rectangular = 0;
}