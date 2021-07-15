/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_rayc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:23:04 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:32:56 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_rayc(t_st *st)
{
	st->rayc.planex = 0;
	st->rayc.planey = 0;
	st->rayc.oldplanex = 0;
	st->rayc.raydirx = 0;
	st->rayc.raydiry = 0;
	st->rayc.mapx = 0;
	st->rayc.mapy = 0;
	st->rayc.sidedistx = 0;
	st->rayc.sidedisty = 0;
	st->rayc.deltadistx = 0;
	st->rayc.deltadisty = 0;
	st->rayc.stepx = 0;
	st->rayc.stepy = 0;
}
